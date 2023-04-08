/*
 * Program to implement main function
 * 
 * Compilation : gcc main.c priority_queue.c heap.h
 * Execution : ./a.out
 *
 * @Ritik  , (1910990138) , 06/09/21 .
 * Project in C
 */
#include<stdio.h>
#include"heap.h"
//max_cmp is used to make heap, a max heap
int max_cmp(void * a,void *b)
 {

 	int* n1 = (int *) a;
 	int *n2 = (int *) b;
 	 	
 	return ( *n1 > *n2 ? 1 : 0);
 }
//min_cmp is used to make heap  a min heap
int min_cmp(void * a,void *b)
 {

        int* n1 = (int *) a;
        int *n2 = (int *) b;

        return ( *n1 < *n2 ? 1 : 0);
 }
//This driver function just checks functionality of max heap, for min heap we just need to change max_cmp to min_cmp
int main()
 {
    int a = 4;
    printf("Inserted : %d\n",a);
    push(&a,max_cmp);

    int b = 2;
    printf("Inserted : %d\n",b);
    push(&b,max_cmp);

    int c=3;
    printf("Inserted : %d\n",c);
    push(&c,max_cmp);

    int *mx = (int*) front();
    printf("Max element : %d\n",*mx);

    mx = (int*) pop(&max_cmp);
    printf("Deleted : %d\n",*mx);

    mx = (int*) front();
    printf("Current Max element : %d\n",*mx);

    if(is_empty())
    {
       printf("Priority queue is empty\n");  	    
    }
    else
    {
       printf("Priority queue is not empty\n");	     
    }

    printf("It's size is %d\n",get_size());

    while(!is_empty())
    {
    mx = (int*)pop(&max_cmp);
    printf("Deleted : %d\n",*mx);
    }

    if(is_empty())
    {
       printf("Priority queue is empty\n");
    }
    else
    {
       printf("Priority queue is not empty\n");
    }
   
    
 	
 }
