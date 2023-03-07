#include "heap_buffer_overflow.h"
#include <cstring>

void heap_buffer_overflow(int a, int b, const std::string& c) {
  if (a > 100 && b < 100 && c == "Awesome Fuzzing!") {
    // Trigger a heap buffer overflow by writing the 8-byte string "too long" into
    // an array allocated with a single-byte capacity.
    char *s = (char *)malloc(1);
    strcpy(s, "too long");
  }
}
