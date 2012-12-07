#include <stdio.h>

#define USAGE "usage: %s <device>"

void usage(string runpath) {
  printf(
	 "usage: %s <device>",
	 runpath
	 );
}

int main(int argc, char *argv[]) {
  if(argc < 2) {
    usage(argv[0]);
    return 1;
  }
  char *device = argv[1];
  return 0;
}
