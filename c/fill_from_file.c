#include <assert.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Reference:
// https://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c

// compilation: gcc -std=c11 read_fixed.c

/**
 * Fill in the buffer with content from file `filename` from start position
 * `start_pos` and the following size `usize` (in bytes)
 */
int fill_from_file(char *filename, char **buffer, uint32_t start_pos,
                   uint32_t size) {
  FILE *fp;
  int fd, num_read;
  fp = fopen(filename, "r");
  if (!fp) {
    // cannot open the file
    perror(filename);
    exit(1);
  }
  // no need to check start_pos as read() will return 0 for eof
  fseek(fp, start_pos, SEEK_SET);
  fd = fileno(fp);
  if ((num_read = read(fd, *buffer, size)) == -1) {
    fclose(fp);
    fputs("read fails", stderr);
    exit(1);
  }
  return num_read;
}

int main() {
  char *filename = "/tmp/test.txt";
  char *outname = "/tmp/out.txt";
  char *content = "ABCDEFGHIJKLMN";
  FILE *fp = fopen(filename, "w");
  fputs(content, fp);
  fclose(fp);
  FILE *out = fopen(outname, "w+");
  int buffer_size = 3;
  char *buffer = (char *)malloc(sizeof(char) * buffer_size);
  for (int i = 0; i < 14; i++) {
    int num_read =
        fill_from_file(filename, &buffer, i * buffer_size, buffer_size);
    for (int j = 0; j < num_read; j++) {
      assert(buffer[j] == content[i * buffer_size + j]);
      fputc(buffer[j], out);
    }
  }
  fclose(out);
  // file `filename` and file `outname`'s content should be the same
  return 0;
}
