#include <stdio.h>

#define CAPSIZE 1024

void usage(char runpath[]) {
  printf(
	 "usage: %s <device>\n",
	 runpath
	 );
}

int main(int argc, char *argv[]) {
  if(argc < 2) {
    usage(argv[0]);
    return 1;
  }
  char *device = argv[1];
  char *filter;

  if(argc > 2) {
    filter = argv[2];
  } else {
    filter = "";
  }
  cap(device, filter, CAPSIZE);
  return 0;
}
