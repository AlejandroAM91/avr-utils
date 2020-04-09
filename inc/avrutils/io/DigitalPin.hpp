#ifndef AVRUTILS_DIGITAL_PIN_HPP
#define AVRUTILS_DIGITAL_PIN_HPP

#include "Pin.hpp"
#include "Port.hpp"

namespace avrutils {
namespace io {

class DigitalPin {
public:
    DigitalPin(Port port, int npin);

    void setMode(PinMode value);

    PinValue getValue();
    void setValue(PinValue value);

private:
    int _npin;
    Port _port;
};

};  // namespace io
};  // namespace avrutils

#endif
