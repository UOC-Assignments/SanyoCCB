#ifndef SanyoCCBv2_h
#define SanyoCCBv2_h

#include <inttypes.h>
#include "Arduino.h"

#define _CCB_SEND    0
#define _CCB_RECEIVE 1

// Base delay (us).  Also used to time the CL (clock) line.
// 100us should be enough even for slow CCB devices.
//
// 40Khz -> 25us cicles 
// 40Khz -> 20us cicles 
// 60Khz -> 16us cicles 

#define CCB_DELAY 20
//#define CCB_DELAY 50000000 //DEBUG (SLOW-MOTION)

class SanyoCCB {
	public:
		SanyoCCB(uint8_t, uint8_t, uint8_t, uint8_t);
		void init();
		uint8_t diPinState();
		void read(byte, byte*, int8_t);
		void write(byte, byte*, int8_t);
	private:
		void writeByte(byte);
		byte readByte();
		void ccb(byte, byte*, int8_t, uint8_t);
		int _do_pin;
		int _cl_pin;
		int _di_pin;
		int _ce_pin;
};

#endif

