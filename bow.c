#include "bow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct bag_struct *new_bag() {
  struct bag_struct *s;
  s = malloc(sizeof(struct bag_struct));
  s->bag = NULL;
  s->bag_size = 0;
  s->total_word = 0;
  return s;
}

int bagsearch(struct bag_struct *bow, char *word) {
  int m;
  int cmp,start,end;
  m = (bow->bag_size-1) / 2;
  start = 0;
  end = bow->bag_size-1;
  cmp = strcmp(bow->bag[m-1].word,word);
  if(m == bow->bag_size) {
    return 0;
  }
  while(start <=end) {
    m = (start + end)/2;
    if(cmp < 0) {
      start = m + 1;
    }
    else if(cmp > 0) {
      end = m - 1;
    }
    else {
      return m;
    }
      printf("%s %s\n",bow->bag[m - 1].word,word);
   }
   return start;
}

int is_letter(char character) {
  if(isalpha(character)) {
    return 1;
  }
  else {
    return 0;
  }
}

char *get_word(char **string_ptr) {
  char *word;
  int pos;
  word = malloc(919);
  while(is_letter(**string_ptr) == 0 && (**string_ptr != '\0')) {
    *string_ptr+=1;
    if(**string_ptr == '\0') {
      return NULL;
    }
  }
  pos = 0;
  while(is_letter(**string_ptr)!=0) {
    word[pos] = **string_ptr;
    *string_ptr+=1;
    word[pos+1] = '\0';
    pos++;
    if(**string_ptr == '\0') {
      return NULL;
    }
  }
  return word;
}

struct word_count_struct *new_word_count(char *word){
  struct word_count_struct *s2;
  s2= malloc(sizeof(struct word_count_struct));
  s2->word = word;
  s2->count = 1;
  return s2;
}

void print_word_count(struct word_count_struct *s_word) {
  printf("%s:%d\n",s_word->word,s_word->count);
}

void free_bag(struct bag_struct *s_bag) {
  int i;
  for(i = 1; i < s_bag->total_word; i++) {
    free(s_bag->bag[i].word);
  }
}
void print_bag(struct bag_struct *s_bag) {
  int i;
  for(i = 0; i < s_bag->bag_size; i++) {
    printf("%d Words: %s\n",i,s_bag->bag[i].word);
  }
  printf("Total words: %d\n",s_bag->total_word);
}



void add_word(struct bag_struct *bow, char *word) {
  struct word_count_struct *s;
  int i,pos;
  s = new_word_count(word);
  i = 0;
  i = bow->bag_size;
  bow->bag_size = bow->bag_size + 1;
  bow->total_word = bow->total_word + 1;
  bow->bag = realloc(bow->bag,sizeof(struct word_count_struct) * (bow->bag_size));
  pos = bagsearch(bow,word);
  memcpy(&bow->bag[pos + 1],&bow->bag[pos],sizeof(struct word_count_struct) * (bow->bag_size - pos));
  memcpy(&bow->bag[i],s,sizeof(struct word_count_struct));
  free(s);
}


void add_text(struct bag_struct *bow, char *line) {
  char *word;
  while(*line) {
    word = get_word(&line);
    if(word !=NULL) {
      add_word(bow,word);
      word = realloc(word,strlen(line) + 1);
    }
  }
}

void read_sms_data(struct bag_struct *bow, char *label) {
  FILE *fp;
  char *s;
  fp = fopen("SMSSpamCollection.txt","r+");
  fgets(s,918,fp);
  printf("%s",s);
}

void differences(struct bag_struct *ham, struct bag_struct *spam) {
	
}

