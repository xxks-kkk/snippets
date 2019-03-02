#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// read the whole content of the file into buffer
char *read_whole_file(char *filename) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (!fp) {
    perror(filename);
    exit(1);
  }
  // get the file size first
  fseek(fp, 0L, SEEK_END);
  uint32_t file_size = ftell(fp);
  rewind(fp);
  char *buffer = (char *)malloc(sizeof(char) * file_size);
  if (fread(buffer, file_size, 1, fp) != 1) {
    fclose(fp);
    free(buffer);
    fputs("read fails", stderr);
    exit(1);
  }
  return buffer;
}

int main() {
  char *filename = "/tmp/read_whole_file_test.txt";
  char *outname = "/tmp/read_whole_file_out.txt";
  char *content = "ABCDEFGHIJKLMN";
  FILE *fp = fopen(filename, "w");
  fputs(content, fp);
  fclose(fp);
  FILE *out = fopen(outname, "w+");
  char *buffer = read_whole_file(filename);
  fputs(buffer, out);
  fclose(out);
  // let's compare the file content
  char command[80];
  strcpy(command, "diff ");
  strcat(command, filename);
  strcat(command, " ");
  strcat(command, outname);
  assert(system(command) == 0);
  free(buffer);
}
