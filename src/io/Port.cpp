#include <avrutils/io/Port.hpp>

namespace avrutils {
namespace io {

Port::Port(ADDR ddr, ADDR pin, ADDR pout) : _ddr(ddr), _pin(pin), _pout(pout) {
    *_ddr = 0xff;
    *_pout = 0;
}

void Port::write(int npin, bool value) {
    if (value) {
        *_pout |= (1 << npin);
    } else {
        *_pout &= ~(1 << npin);
    }
}

};  // namespace io
};  // namespace avrutils
