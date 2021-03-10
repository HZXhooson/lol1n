#ifndef __LOLIN_UC8151D_H
#define __LOLIN_UC8151D_H

#ifdef __AVR__
  #include <avr/pgmspace.h>
#elif defined(ESP8266) || defined(ESP32)
 #include <pgmspace.h>
#else
 #define pgm_read_byte(addr) (*(const unsigned char *)(addr)) ///< read bytes from program memory
#endif

#include "LOLIN_EPD.h"


/**************************************************************************/
/*!
    @brief  Class for interfacing with IL3897 EPD drivers
*/
/**************************************************************************/
class LOLIN_UC8151D : public LOLIN_EPD {
	public:

	  LOLIN_UC8151D(int width, int height, int8_t SID, int8_t SCLK, int8_t DC, int8_t RST, int8_t CS, int8_t BUSY = -1);
	  LOLIN_UC8151D(int width, int height, int8_t DC, int8_t RST, int8_t CS, int8_t BUSY = -1);

	void begin(bool reset=true);
	
	void drawPixel(int16_t x, int16_t y, uint16_t color);
	
	void display();
	void update();
	
	void clearBuffer();
	void clearDisplay();

	void deepSleep();



protected:
	void readBusy();
	int _height_8bit;// height 8-bit alignment
};

#endif