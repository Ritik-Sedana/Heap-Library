/*
 * Program for defining functions
 * 
 * Compilation : gcc main.c priority_queue.c heap.h
 * Execution : ./a.out
 *
 * @Ritik  , (1910990138) , 06/09/21 .
 * Project in C
 */

#include<stdbool.h>
//all the variables used in priority_queue.c
extern int total_size;
extern int  call;
extern void **priority_queue;
extern int size;
//all the functions used in priority_queue.c
void allocate_memory_to_priority_queue();
bool is_empty();
int get_size();
void* front();
void push(void* ,int( *cmp)(void* ,void*));
void* pop(int( *cmp)(void* ,void*));
