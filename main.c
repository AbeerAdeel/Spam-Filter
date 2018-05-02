#include "bow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *sentence = "#The quick brown fox jumped over 23&%^24 the lazy dogs.";
  struct bag_struct *s_bag;
  s_bag = new_bag();
  printf("sentence = \"%s\"\n", sentence);
  add_text(s_bag,sentence);
  print_bag(s_bag);
  read_sms_data(s_bag,sentence);
  free_bag(s_bag);
  return 0;
}
