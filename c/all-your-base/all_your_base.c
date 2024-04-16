#include "all_your_base.h"
#include <math.h>

size_t rebase(int8_t * digits, int16_t input_base, 
              int16_t output_base, size_t input_length){
    if (!input_length || input_base < 2 || output_base < 2) return 0;
     
    uint32_t value10 = 0;
    for (size_t index = input_length; index > 0; --index){
        if (digits[index - 1] < 0 || digits[index - 1] >= input_base) return 0;
        value10 += digits[index - 1] * pow(input_base, input_length - index);
    }

    if (value10 == 0) return 1;

    size_t length = log10(value10) / log10(output_base) + 1;
    size_t index = 0;
    while (value10) {
        digits[length - 1 - index++] = value10 % output_base;
        value10 /= output_base;
    }
    
    return length;
}
