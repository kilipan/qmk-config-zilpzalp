#include "quantum.h"

// readability
#define ___ KC_NO

#define LAYOUT_zilpzalp( \
              K01, K02, K03, K04,    K05, K06, K07, K08,      \
              K11, K12, K13, K14,    K15, K16, K17, K18,      \
         K20, K21, K22, K23,              K26, K27, K28, K29, \
                        K33, K34,    K35, K36                 \
    )                                        \
    {                                        \
        { K01,   K02,   K03,   K04 }, \
        { K11,   K12,   K13,   K14 }, \
        { K20,   K21,   K22,   K23 }, \
        { K33,   K34,   K35,   K36 }, \
        { K26,   K27,   K28,   K29 }, \
        { K15,   K16,   K17,   K18 }, \
        { K05,   K06,   K07,   K08 } \
    }
