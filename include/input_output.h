#pragma once

struct info_develop
{
    int number;
    char* description;
    int priority;
    char *date;
} ;

//void input_dev(struct info_develop* task);
struct info_develop* input_devs(int *tasks_amount);
struct info_develop *input_dev();
void sort_tasks_array(struct info_develop *tasks_array, int tasks_amount);
void output_dev(const struct info_develop* task);
_Bool string_is_int(const char *str);
int string_to_int(const char *str);
void read_description(char **desc);
void free_dev(struct info_develop** task, int shift);