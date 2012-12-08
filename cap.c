#include <pcap.h>

int cap(char *device, char *filter, int size) {
  char errbuf[PCAP_ERRBUF_SIZE];

  pcap_t *p;

  struct bpf_program fp;
  bpf_u_int32 mask;
  bpf_u_int32 net;

  if(pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Can't get netmask for device %s\n", device);
    net = 0;
    mask = 0;
  }

  p = pcap_open_live(device, BUFSIZ, 1, size, errbuf);
  if(p == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
    return 2;
  }
  if(pcap_compile(p, &fp, filter, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter, errbuf);
    return 2;
  }
  pcap_close(p);
  return 0;
}
