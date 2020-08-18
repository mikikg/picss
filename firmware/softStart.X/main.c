/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F15313
        Driver Version    :  2.00
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

//10us tajmer0 interupt
void TMR0_ISR(void) {
    // clear the TMR0 interrupt flag
    PIR0bits.TMR0IF = 0;
    
    // add your TMR0 interrupt custom code
    brojac1++;
    brojac2++;
    //brojac3++;
    //brojac4++;

    if ((brojac1 >= zadat_ugao) && (brojac1 <= (zadat_ugao+200)) && scr_out_enable ) {
        NCO1CONbits.N1EN = true; //opcija za češalj
        //SCR_OUT=1; //opcija za puls
    } else {
        NCO1CONbits.N1EN = false;
        //SCR_OUT=0;
    }
}

//Zero cros interupt
void ZCD_ISR(void) {
    if (brojac1 > 50) { //ZCD filter, prolaz pa sledeci tek moze za 50*10us
        //ok, ZCD akcija, ugasi triak gate signal
        
        //SCR_OUT = 0;
        NCO1CONbits.N1EN = false;
        
        //ocisti brojac
        brojac1 = 0;
        zadat_ugao = zadat_ugao_adc;
    }
    // Clear the ZCD interrupt flag
    PIR2bits.ZCDIF = 0;  
}

//LPF
#define FILTER_OVERSAMP 32
inline unsigned int low_pass_filter_1(unsigned int x) {
	static unsigned int samples[FILTER_OVERSAMP], i = 0, total = 0;
	/* Update the moving average */
	total += x - samples[i];
	samples[i] = x;
	/* Update the index */
	i = (i==(FILTER_OVERSAMP-1) ? 0 : i+1);
	return total/FILTER_OVERSAMP;
}

//LPF1
#define FILTER_OVERSAMP1 32
inline unsigned int low_pass_filter_2(unsigned int x1) {
	static unsigned int samples1[FILTER_OVERSAMP1], i1 = 0, total1 = 0;
	/* Update the moving average */
	total1 += x1 - samples1[i1];
	samples1[i1] = x1;
	/* Update the index */
	i1 = (i1==(FILTER_OVERSAMP1-1) ? 0 : i1+1);
	return total1/FILTER_OVERSAMP1;
}

/*
                         Main application
 */

#define inactive_angle 2000 // za brojac kada je neaktivan
#define max_angle 1000 //vreme potrebno za 1 poluperiodu 1000*10us=10ms
#define min_angle 50 //za podesavanje

void main(void) {
        
    // initialize the device
    SYSTEM_Initialize();
    // When using interrupts, enable the Global and Peripheral Interrupts
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_StartTimer();
    
    //promenljive
    int taster_time, slope_counter, tmp_zadato, slope_increment;
    bool slope_up_active;

    while (1)
    {
        // ADC
        slope_increment = low_pass_filter_2(ADC_GetConversion(pot_slope));
        tmp_zadato = max_angle - low_pass_filter_1(ADC_GetConversion(pot_power));
        if (tmp_zadato < min_angle) tmp_zadato = min_angle;
        
        // Taster za start/stop slope
        if (RA3 == 0) { 
            if (taster_time ++ == 200) {
                //akcija
                scr_out_enable =! scr_out_enable;
                if (scr_out_enable == true) {
                    slope_up_active = true;
                    slope_counter = max_angle;
                }
            }
        } else taster_time = 0;

        // Slope
        if (slope_up_active == true) {
            if (brojac2 >= slope_increment) {
                slope_counter --;
                if (slope_counter <= 0 || slope_counter < tmp_zadato) {
                    //zavrsio slope
                    slope_up_active = false;
                } else {
                    //radi slope
                }
                brojac2 = 0;
            }
        }
        
        if (brojac1 > 1500) { 
            //ako odbrojao vise od 15ms bez ZCD, nema AC, gasi
            scr_out_enable = false;
            slope_up_active = false;
            brojac1 = 0;
        } 
        
        // Out
        if (scr_out_enable) {
            if (tmp_zadato > 990) { //kada je minimum tj off
                zadat_ugao_adc = inactive_angle;
            } else {
                if (slope_up_active) {
                    zadat_ugao_adc =  slope_counter;
                } else {
                    zadat_ugao_adc = tmp_zadato;
                }
            }
            //za relay kada je pri max snazi
            if (zadat_ugao_adc < 60) RLY_OUT = 1;
            if (zadat_ugao_adc > 80) RLY_OUT = 0;
        } else {
            //ugaseno
            slope_counter = 0;
            zadat_ugao_adc = inactive_angle;
            RLY_OUT = 0;
        }
        
    }
}

/**
 End of File
*/