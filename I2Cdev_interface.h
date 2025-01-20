#ifndef _I2CDEV_INTERFACE_H_
#define _I2CDEV_INTERFACE_H_

/*
    IIC hardware abstraction layer is used to manage hardware IIC and software IIC, and provide a unified interface to the outside world, allowing the outside world to call different IIC buses
*/


#include <iostream>
#include <vector>
#include <memory>
#include <string>

class IICInterface {
public:
    virtual ~IICInterface() = default;

    virtual std::string getName() const = 0;

    virtual void begin(void);
    virtual void end(void);
    virtual void beginTransmission(uint8_t address);
    virtual void beginTransmission(int address);
    virtual uint8_t endTransmission(uint8_t sendStop);
    virtual uint8_t endTransmission(void);

    virtual size_t write(uint8_t data);
    virtual size_t write(const uint8_t *data, size_t quantity);

    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop);
    virtual uint8_t requestFrom(int address, int quantity, int sendStop);
    virtual uint8_t requestFrom(uint8_t address, uint8_t quantity);
    virtual uint8_t requestFrom(int address, int quantity);

    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);

};




#endif