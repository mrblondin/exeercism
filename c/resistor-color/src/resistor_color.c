#include "resistor_color.h"

int color_code(resistor_band_t color){
    return color; 
}

resistor_band_t * colors(){
    static resistor_band_t codes[WHITE + 1];  
    for (int i = BLACK; i <= WHITE; i++)
        codes[i] = i;
    return codes;
}
