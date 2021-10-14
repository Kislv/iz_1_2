#include "stdio.h"
#include "stdlib.h"
#include "../include/input_output.h"

int main(){
    int tasks_amount = 0;
    struct info_develop* tasks_array = input_devs(&tasks_amount);
    sort_tasks_array(tasks_array,tasks_amount);
    for(int i = 0;i< tasks_amount; ++i){
        output_dev(&tasks_array[i]);
    }

    for(int i = 0;i< tasks_amount; ++i){
        free_dev( &tasks_array, i);
    }
    free(tasks_array);

    return 0;
}
