#include "stack_buffer_overflow.h"
#include <cstring>

bool stack_buffer_overflow(const uint8_t *data, size_t data_size) {
  // The bug can be triggered with a single input: "CI Fuzz". This string has only 7 bytes,
  // but the code tries to access the 8th character (data[7]).
  // This is a typical off-by-one errors we often see in C/C++ code. Here, it can be fixed
  // by checking if data_size is strictly larger than 7 (data_size > 7).
  return data_size >= 7 &&
    data[0] == 'C' &&
    data[1] == 'I' &&
    data[2] == ' ' &&
    data[3] == 'F' &&
    data[4] == 'u' &&
    data[5] == 'z' &&
    data[6] == 'z' &&
    data[7] == '!';   // Ouch!
}