#include <avrutils/io/DigitalPin.hpp>

namespace avrutils {
namespace io {

DigitalPin::DigitalPin(Port port, int npin) : _port(port), _npin(npin) {
}

void DigitalPin::write(bool value) {
    _port.write(_npin, value);
}

};  // namespace io
};  // namespace avrutils
