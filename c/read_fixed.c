#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Reference:
// https://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c

// compilation: gcc -std=c11 read_fixed.c

/**
 * Fill in the buffer with content from file `filename` from start position
 * `start_pos` and the following size `usize` (in bytes)
 */
char *fill_from_file(char *filename, uint32_t start_pos, uint32_t size) {
  char *buffer = (char *)malloc(sizeof(char) * size);
  FILE *fp;
  fp = fopen(filename, "r");
  if (!fp) {
    perror(filename);
    exit(1);
  }
  fseek(fp, start_pos, SEEK_SET);
  if (fread(buffer, size, 1, fp) != 1) {
    fclose(fp);
    free(buffer);
    fputs("read fails", stderr);
    exit(1);
  }
  return buffer;
}

int main() {
  char *filename = "/tmp/test.txt";
  char *outname = "/tmp/out.txt";
  char *content = "ABCDEFGHIJKLMN";
  FILE *fp = fopen(filename, "w");
  fputs(content, fp);
  fclose(fp);
  FILE *out = fopen(outname, "w+");
  char *buffer;
  int buffer_size = 2;
  for (int i = 0; i < 14 / buffer_size; i++) {
    buffer = fill_from_file(filename, i * buffer_size, buffer_size);
    for (int j = 0; j < buffer_size; j++) {
      assert(buffer[j] == content[i * buffer_size + j]);
      fputc(buffer[j], out);
    }
    free(buffer);
  }
  fclose(out);
  // file `filename` and file `outname`'s content should be the same
  return 0;
}
