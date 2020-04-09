#include <avrutils/io/Port.hpp>

namespace avrutils {
namespace io {

Port::Port(ADDR ddr, ADDR pin, ADDR pout) : _ddr(ddr), _pin(pin), _pout(pout) {
    *_ddr = 0xff;
    *_pout = 0;
}

void Port::setMode(int npin, PinMode mode) {
    if (mode) {
        *_ddr |= (1 << npin);
    } else {
        *_ddr &= ~(1 << npin);
    }
}

PinValue Port::getValue(int npin) {
    int value = *_pin & (1 << npin);
    if (value) {
        return HIGH;
    } else {
        return LOW;
    }
}

void Port::setValue(int npin, PinValue value) {
    if (value) {
        *_pout |= (1 << npin);
    } else {
        *_pout &= ~(1 << npin);
    }
}

};  // namespace io
};  // namespace avrutils
