#include <U8g2lib.h>


u8g2_t u8g2;  // a structure which will contain the data for the display




int main(void) {

    u8g2_SetupBuffer_SDL_128x64_4(&u8g2, &u8g2_cb_r0);  // reset pin not used
    u8x8_InitDisplay(u8g2_GetU8x8(&u8g2));  // initialize the display
    u8g2_SetPowerSave(u8g2_GetU8x8(&u8g2), 0); // wake up display

    
    while (1)
   {
     u8g2_FirstPage(&u8g2);
     do {
         u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tr);
         u8g2_DrawStr(&u8g2, 10, 30, "CYRUS TERMINAL");
         u8g2_DrawStr(&u8g2, 10, 50, "SYSTEM BOOTING...");
     } while (u8g2_NextPage(&u8g2));
        /* code */
    }
    return 0;


}
  
    