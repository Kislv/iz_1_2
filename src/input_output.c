/* Вариант #6
Создать структуру для хранения информации о задаче на разработку:
ее номере, описании, приоритете и дате постановки. Составить с ее использованием программу
 вывода задач в порядке их предстоящего выполнения в соответствии с приоритетом и датой постановки
 (сначала — задачи с большим приоритетом, в случае равенства приоритетов — задачи с более ранней датой).

Задача решена, ревьюер одобрил весь код, при этом есть хотя бы одна настройка от CI и хотя бы один тест,
 которые автоматически запускаются для всех новых изменений и проходят на итоговой версии –  3
Код полностью покрыт юнит-тестами –  1
Настроен и проходит CI: автоматическая сборка, статический анализ, линтеры, valgrind, code coverage, запуск тестов –  1

 */

#include "stdio.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/input_output.h"

#define DEBUG
#define string_max_size 256
#define date_length 12
#define chunk_size 16
#define string_rise 2

_Bool valid_date(const char * str);
_Bool is_dig(char c);

int max_int(const int el1, const int el2){
    if(el1>el2){
        return el1;
    }
    return el2;
}
void swap(struct info_develop* task1,struct info_develop* task2, int max_length_desc){
    int ad_int;
    char ad_str[12]; //
    char ad_desc[max_length_desc];
    ad_int = task1->priority;
    task1->priority= task2->priority;
    task2->priority = ad_int;
    ad_int = task1->number;
    task1->number = task2->number;
    task2->number = ad_int;
    memcpy(ad_str, task1->date, strlen(task1->date));
    memcpy(task1->date, task2->date, strlen(task2->date));
    memcpy(task2->date, ad_str, strlen(ad_str));

    task1->description = (char*)realloc(task1->description, max_length_desc);
    task2->description = (char*)realloc(task2->description, max_length_desc);
    memcpy(ad_desc, task1->description, strlen(task1->description));
    memcpy(task1->description, task2->description, strlen(task2->description));
    memcpy(task2->description, ad_desc, strlen(ad_desc));
}

void sort_tasks_array(struct info_develop *tasks_array, int tasks_amount){
    for(int i =0;i<tasks_amount-1; ++i){
        for(int k =i+1 ;k < tasks_amount; ++k){
            if((tasks_array[i]).priority < (tasks_array[k]).priority){
                swap(&tasks_array[i], &tasks_array[k], max_int(strlen(tasks_array[i].description), strlen(tasks_array[k].description)));
            }
        }
    }

    for(int i =0;i < tasks_amount; ++i){
        for(int k =i ;k < tasks_amount - 1; ++k){
            if((tasks_array[i]).priority == (tasks_array[k]).priority && strcmp(tasks_array[i].date, tasks_array[k].date) < 0){
                swap(&tasks_array[i], &tasks_array[k], max_int(strlen(tasks_array[i].description), strlen(tasks_array[k].description)));
            }
        }
    }
}
struct info_develop* input_devs(int *tasks_amount){
    char str[string_max_size];
    printf("Enter amount of tasks:\n");
    fgets(str,sizeof(str),stdin);
    (*tasks_amount) = 0;
    if(string_is_int(str)){                               // остановился, не работает перевод в int
        (*tasks_amount) = string_to_int(str);
        printf("%d\n",(*tasks_amount));
    }
    struct info_develop *tasks_array = malloc((*tasks_amount) * sizeof (struct info_develop));
    for(int i =0;i<(*tasks_amount);++i){
        tasks_array[i] = *(input_dev());
    }
    return tasks_array;
}

struct info_develop *input_dev(){
    struct info_develop* task = malloc(sizeof(struct info_develop));
    char str[string_max_size];
    printf("Enter number:\n");
    fgets(str,sizeof(str),stdin);
    //scanf("%d", (*task).number);
    #ifdef DEBUG
    printf("%s",str);
    #endif
    if(string_is_int(str)){
        task->number = string_to_int(str);
    }
    else assert("String is not int");
    #ifdef DEBUG
        printf("%d\n",task->number);
    #endif
    printf("Enter priority (1 ... 10):\n");
    fgets(str,sizeof(str),stdin);
    if(string_is_int(str)){
        task->priority = string_to_int(str);
    } else assert("String is not int");
    #ifdef DEBUG
        printf("%d\n",task->priority);
    #endif
    printf("Enter date (format: dd.mm.yyyy):\n");
    fgets(str,sizeof(str),stdin);
    task->date = (char*)malloc (sizeof(char)*date_length);
    if(valid_date(str)){
        memcpy(task->date, str, strlen(str));
    } else assert("Date is not valid");
    #ifdef DEBUG
        printf("%s\n",task->date);
    #endif

    printf("Enter description:\n");
    task->description = NULL;
    read_description(&(task->description));
    #ifdef DEBUG
        printf("%s\n",task->description);
    #endif
    return task;
};

_Bool string_is_int(const char *str){
    if(str == NULL){
        return false;
    }
    for(int i = 0; i < strlen(str)-1;++i){
        if(str[i] < '0' || str[i] > '9'){
            return false;
        }
    }
    return true;

    //while (str+i != '\n' || str+i != EOF)
};
int string_to_int(const char *str){
    int degree = 1;
    int sum =0;
    for(int i = strlen(str)-2; i >= 0;--i){ //в тестах в конце строки добавить \n
        sum += ((str[i]-'0') * degree);
        degree *= 10;
    }
    return sum;
};

 _Bool is_dig(char c){
     if(c>= '0' && c <='9'){
         return true;
     }else return false;
 }
_Bool valid_date(const char * str){
    if(str == NULL) return false;
    if(strlen(str)!=11) return false;
    if(is_dig(str[0]) && is_dig(str[1]) && (str[2] == '.') && is_dig(str[3]) && is_dig(str[4]) && (str[5] == '.') && is_dig(str[6]) && is_dig(str[7]) && is_dig(str[8]) && is_dig(str[9])){
        return true;
    }
    return false;
}

void read_description(char **desc){
     if ((*desc) != NULL) { assert("description is already exist");}
    (*desc) = (char*)malloc(string_max_size); // Memory allocate
    int capacity = string_max_size;
    char chunk[chunk_size];
    int size = 0;
    while(true) {
        fgets(chunk, sizeof(chunk), stdin);
        for (int i = 0;i<sizeof(chunk)-1;i++){
            if (!chunk[i]) return;
            if(size == capacity-2){
                capacity = capacity *string_rise;
                (*desc) = (char*)realloc((*desc),capacity);
            }
            (*desc)[size] = chunk[i];
            ++size;
        }
    }
 }

void output_dev(const struct info_develop* task){
    printf("Number: %d\n", task->number);
    printf("Priority: %d\n", task->priority);
    printf("Date: %s", task->date);
    printf("Description: %s\n\n", task->description);
};

 void free_dev(struct info_develop** task,int shift){
     free(((*task) + shift)->date);
     free(((*task) + shift)->description);
     //free(((*task)));
 }