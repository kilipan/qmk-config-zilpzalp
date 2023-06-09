#include "quantum.h"

#define LAYOUT( \
              K01, K02, K03, K04,    K05, K06, K07, K08,      \
         K20, K11, K12, K13, K14,    K15, K16, K17, K18, K29, \
              K21, K22, K23,              K26, K27, K28,      \
                        K33, K34,    K35, K36                 \
    )                                        \
    {                                        \
        { K01,   K02,   K03,   K04 }, \
        { K11,   K12,   K13,   K14 }, \
        { K20,   K21,   K22,   K23 }, \
        { K36,   K33,   K35,   K34 }, \
        { K29,   K28,   K27,   K26 }, \
        { K18,   K17,   K16,   K15 }, \
        { K08,   K07,   K06,   K05 } \
    }
