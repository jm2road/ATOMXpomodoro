#include "Arduino.h"
#include "M5Atom.h"
#include "LEDBuffer.h"

void LEDBuffer::fillAll(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata)
{
    DisBuff[0] = LED_WIDTH; // width
    DisBuff[1] = LED_HEIGHT; // height
    for (int i = 0; i < 25; i++) {
        this->set(Rdata, Gdata, Bdata, i);
    }
}

void LEDBuffer::fill(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata, uint8_t start_pos, uint8_t end_pos)
{
    DisBuff[0] = LED_WIDTH;
    DisBuff[1] = LED_HEIGHT;
    for (int i = start_pos; i < end_pos; i++) {
        this->set(Rdata, Gdata, Bdata, i);
    }
}

void LEDBuffer::set(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata, uint8_t pos)
{
    DisBuff[LED_BUF_HEAD + pos*LED_RGB_SIZE]   = Rdata;
    DisBuff[LED_BUF_HEAD + pos*LED_RGB_SIZE+1] = Gdata;
    DisBuff[LED_BUF_HEAD + pos*LED_RGB_SIZE+2] = Bdata;
}

void LEDBuffer::clear(void)
{
    DisBuff[0] = LED_WIDTH;
    DisBuff[1] = LED_HEIGHT;
    for (int i = 0; i < LED_MAX; i++) {
        this->set(0, 0, 0, i);
    }
}

void LEDBuffer::display(void)
{
    M5.dis.displaybuff(DisBuff);
}
