#ifndef AVRUTILS_PORT_HPP
#define AVRUTILS_PORT_HPP

#include "glo.hpp"
#include "Pin.hpp"

namespace avrutils {
namespace io {

class Port {
public:
    Port(ADDR ddr, ADDR pin, ADDR pout);

    void setMode(int npin, PinMode value);

    PinValue getValue(int npin);
    void setValue(int npin, PinValue value);

private:
    ADDR _ddr;
    ADDR _pin;
    ADDR _pout;
};

};  // namespace io
};  // namespace avrutils

#endif
