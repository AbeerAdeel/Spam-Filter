#ifndef BOW_H_
#define BOW_H_

struct bag_struct *new_bag();
int bagsearch(struct bag_struct *bow, char *word);
char *get_word(char **string_ptr);
struct word_count_struct *new_word_count(char *word);
void add_word(struct bag_struct *bow, char *word);
void add_text(struct bag_struct *bow, char *line);
void read_sms_data(struct bag_struct *bow,char *label);
void differences(struct bag_struct*ham, struct bag_struct*spam);
int is_letter(char character);
void free_word_count(struct word_count_struct *word_count);
void print_word_count(struct word_count_struct *s_word);
void print_bag(struct bag_struct *s_bag);
void free_bag(struct bag_struct *s_bag);
struct word_count_struct {
	char *word;
	int count;
};

struct bag_struct {
	struct word_count_struct *bag;
	int bag_size;
	int total_word;
};

#endif /* BOW_H_ */

