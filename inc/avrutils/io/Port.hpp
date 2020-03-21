#ifndef AVRUTILS_PORT_HPP
#define AVRUTILS_PORT_HPP

#include "glo.hpp"

namespace avrutils {
namespace io {

class Port {
public:
    Port(ADDR ddr, ADDR pin, ADDR pout);

    void write(int npin, bool value);

private:
    ADDR _ddr;
    ADDR _pin;
    ADDR _pout;
};

};  // namespace io
};  // namespace avrutils

#endif
