#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Compilation: gcc -std=c11 fill_fixed.c

/**
 * fill the given `buffer` with size `size` with `pattern`
 * This function is useful when you want to fill a large buffer with certain
 * pattern (e.g., fill the buffer with all 'A')
 */
int fill_fixed(void *buffer, int size, char *pattern, int pattern_size) {
  int left_to_write = size;
  int write_start = 0;
  int n_to_write = pattern_size;
  while (left_to_write > 0) {
    if (write_start + n_to_write > size) {
      n_to_write = left_to_write;
    }
    // +1 due to snprintf's size parameter includes '\0' as well
    int write_size =
        snprintf(buffer + write_start, n_to_write + 1, "%s", pattern);
    // snprintf return number of characters written excluding '\0'
    assert(write_size == pattern_size);
    write_start += write_size;
    left_to_write -= write_size;
  }
  return 0;
}

int main() {
  /* test case 1 */
  int buffer_size = 5;
  char *buffer = (char *)malloc(sizeof(char) * buffer_size);
  fill_fixed(buffer, buffer_size, "A", 1);
  for (int i = 0; i < buffer_size; i++) {
    assert(buffer[i] == 'A');
  }
  free(buffer);

  /* test case 2 */
  buffer_size = 107374182;
  buffer = (char *)malloc(sizeof(char) * buffer_size);
  fill_fixed(buffer, buffer_size, "AAAAA", 5);
  for (int i = 0; i < buffer_size; i++) {
    assert(buffer[i] == 'A');
  }
  free(buffer);
}
