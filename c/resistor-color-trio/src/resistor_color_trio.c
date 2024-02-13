#include "resistor_color_trio.h"
#include "math.h"

resistor_value_t color_code(resistor_band_t * color){
    resistor_value_t value;
    value.value = pow(10, color[2]) * (color[0] * 10 + color[1]);
    if (value.value / 1000 > 0){
        value.value /= 1000; 
        value.unit = KILOOHMS;
    }else
        value.unit = OHMS;
    return value;
}
