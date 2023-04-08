/*
 * Program to implement priority_queue using heap
 * 
 * Compilation : gcc main.c priority_queue.c heap.h
 * Execution : ./a.out
 *
 * @Ritik  , (1910990138) , 06/09/21 .
 * Project in C
 */

/*
 * Time complexity:
 *
 * push  : O(log(n))
 *
 * pop   : O(log(n))
 *
 * front : O(1) 
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
/*total_size is memory allocated to priority_queue
call is just a variable used to know if we need to allocate memory or not
priority_queue is our container which uses heap to store data according to their priority*/

int total_size = 3;
int  call = 0;
//dynamic priority_queue which is basically complete binary tree in the form of array
void **priority_queue;

int size = 0;

//allocates memory to priority_queue
void allocate_memory_to_priority_queue()
 {
    //call == 0 means no memory has been allocated to our priority_queue

    if(call == 0){

      //allocating memory to priority_queue

      priority_queue = (void**) calloc(total_size , sizeof(priority_queue[0]) );
      return ;
    }
    //every time priority_queue is about to get full total size doubles itself

    total_size *= 2;
    void **temp;

    temp = (void**) calloc(total_size ,sizeof(priority_queue[0]));
    for(int i = 0 ; i < (int) size; ++i)
    temp[i] = priority_queue[i];
    priority_queue = temp;


 }

//function to check is priority_queue is empty or not

bool is_empty()
 {
    return (size == 0);
 }
//function to get size of priority_queue

int  get_size()
 {
    return size;
 }
//return minimum element if it is min heap or maximum element if it is max heap in O(1)

void* front()
 {
    assert(size > 0);
    return priority_queue[0];
 }

//function to push inside priority_queue in O(log(n)) time

void push(void* element,int( *cmp)(void* ,void*))
 {
    if(!call || size == total_size - 1)
    {
        allocate_memory_to_priority_queue();

    }

    //pushing element in such a way that complete binary tree properties are still maintained
    priority_queue[size] = element;
    size++;
    call++;
    int  childIndex = size - 1;
    while(childIndex>0)
    {


    int  parentIndex = (childIndex - 1)/2;

    //for min heap child should never be smaller than parent and for max heap child should never be greater than parent
    if(cmp(priority_queue[childIndex],priority_queue[parentIndex])==1)
    {
        void* temp= priority_queue[childIndex];
        priority_queue[childIndex] = priority_queue[parentIndex];
        priority_queue[parentIndex] = temp;
    }
    else
    {
        break;
    }
    childIndex = parentIndex;

    }
 }

//function to remove element from priority_queue on the basis of priority in O(log(n)) time complexity.

void* pop(int( *cmp)(void* ,void*))
 {
    void* ans =priority_queue[0];
    priority_queue[0] =priority_queue[size-1];
    size--;

    // down heapify

    int parentIndex = 0 ;

    //for any index it's children are stored at 2 * parentIndex + 1 and at 2 * parentIndex + 2.

    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;

    //maintaining the property of complete binary tree

    while(leftChildIndex < size)
    {
        int minIndex = parentIndex;

        //finding minimum between parent, left child and right child

        if(cmp(priority_queue[minIndex] , priority_queue[leftChildIndex])==0)
        {
                minIndex = leftChildIndex;
        }
        if(rightChildIndex < size && cmp( priority_queue[minIndex] , priority_queue[rightChildIndex] )==0)
        {
                minIndex = rightChildIndex;
        }

        //if minIndex is parent means it satisfies properties of complete binary tree

        if(minIndex == parentIndex)
        {
                break;
        }

        //swapping to make it complete binary tree

        void* temp = priority_queue[minIndex];
        priority_queue[minIndex] = priority_queue[parentIndex];
        priority_queue[parentIndex] =  temp;
        parentIndex = minIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
    }
    return ans ;

 }

