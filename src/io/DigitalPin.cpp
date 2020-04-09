#include <avrutils/io/DigitalPin.hpp>

namespace avrutils {
namespace io {

DigitalPin::DigitalPin(Port port, int npin) : _port(port), _npin(npin) {
}

void DigitalPin::setMode(PinMode mode) {
    _port.setMode(_npin, mode);
}

PinValue DigitalPin::getValue() {
    return _port.getValue(_npin);
}

void DigitalPin::setValue(PinValue value) {
    _port.setValue(_npin, value);
}

};  // namespace io
};  // namespace avrutils
