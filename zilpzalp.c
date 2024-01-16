#include "zilpzalp.h"

void keyboard_pre_init_kb(void) {
    // Power on the addressable RGB LED on XIAO RP2040
    setPinOutput(GP11);
    writePinHigh(GP11);
}
