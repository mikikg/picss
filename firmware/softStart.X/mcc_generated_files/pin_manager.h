/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F15313
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set pot_slope aliases
#define pot_slope_TRIS                 TRISAbits.TRISA0
#define pot_slope_LAT                  LATAbits.LATA0
#define pot_slope_PORT                 PORTAbits.RA0
#define pot_slope_WPU                  WPUAbits.WPUA0
#define pot_slope_OD                   ODCONAbits.ODCA0
#define pot_slope_ANS                  ANSELAbits.ANSA0
#define pot_slope_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define pot_slope_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define pot_slope_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define pot_slope_GetValue()           PORTAbits.RA0
#define pot_slope_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define pot_slope_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define pot_slope_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define pot_slope_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define pot_slope_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define pot_slope_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define pot_slope_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define pot_slope_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set pot_power aliases
#define pot_power_TRIS                 TRISAbits.TRISA1
#define pot_power_LAT                  LATAbits.LATA1
#define pot_power_PORT                 PORTAbits.RA1
#define pot_power_WPU                  WPUAbits.WPUA1
#define pot_power_OD                   ODCONAbits.ODCA1
#define pot_power_ANS                  ANSELAbits.ANSA1
#define pot_power_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define pot_power_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define pot_power_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define pot_power_GetValue()           PORTAbits.RA1
#define pot_power_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define pot_power_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define pot_power_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define pot_power_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define pot_power_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define pot_power_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define pot_power_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define pot_power_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set kbd_in aliases
#define kbd_in_PORT                 PORTAbits.RA3
#define kbd_in_WPU                  WPUAbits.WPUA3
#define kbd_in_GetValue()           PORTAbits.RA3
#define kbd_in_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define kbd_in_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set scr_out aliases
#define scr_out_TRIS                 TRISAbits.TRISA4
#define scr_out_LAT                  LATAbits.LATA4
#define scr_out_PORT                 PORTAbits.RA4
#define scr_out_WPU                  WPUAbits.WPUA4
#define scr_out_OD                   ODCONAbits.ODCA4
#define scr_out_ANS                  ANSELAbits.ANSA4
#define scr_out_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define scr_out_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define scr_out_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define scr_out_GetValue()           PORTAbits.RA4
#define scr_out_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define scr_out_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define scr_out_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define scr_out_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define scr_out_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define scr_out_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define scr_out_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define scr_out_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set reley_out aliases
#define reley_out_TRIS                 TRISAbits.TRISA5
#define reley_out_LAT                  LATAbits.LATA5
#define reley_out_PORT                 PORTAbits.RA5
#define reley_out_WPU                  WPUAbits.WPUA5
#define reley_out_OD                   ODCONAbits.ODCA5
#define reley_out_ANS                  ANSELAbits.ANSA5
#define reley_out_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define reley_out_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define reley_out_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define reley_out_GetValue()           PORTAbits.RA5
#define reley_out_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define reley_out_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define reley_out_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define reley_out_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define reley_out_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define reley_out_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define reley_out_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define reley_out_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/