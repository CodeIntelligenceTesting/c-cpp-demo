#include "heap_buffer_overflow.h"
#include <cifuzz/cifuzz.h>

FUZZ_TEST_SETUP() {}

FUZZ_TEST(const uint8_t *data, size_t size) {
  heap_buffer_overflow(data, size);
}
