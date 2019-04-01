#include <assert.h>
#include <fcntl.h>
#include <float.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  struct rlimit rlim;
  int ret = getrlimit(RLIMIT_STACK, &rlim);
  assert(ret == 0);
  printf("stack soft limit: %ju\n", rlim.rlim_cur);
  printf("stack hard limit: %ju\n", rlim.rlim_max);

  return 0;
}
