# Library For priority queue using heap
### Goals 
1) The main goal was to implement a priority queue that has key functions like
      1) inserting a new element
      2) removing the element according to their priority 
      3) get the element according to their priority

2) Implementing it in such a way that every major operation takes logarithmic running time 
3) Making priority queue using heap in C language, as there is no inbuilt library for this. 

### Description:

###### What is priority queue using heap?

In computer science, a priority queue is an abstract data type similar to a regular queue or stack data structure in which each element is arranged on the basis of its priority.
Since we are implementing priority queue using heap it will be useful to extract the element on the basis of priority, remove it.<br>

###### What is heap?
A Heap is a special Tree-based data structure in which the tree is a complete binary tree.
In a Min-Heap the key present at the root node must be minimum among the keys present at all of its children and is reverse in case of Max-Heap. The same property must be recursively true for all sub-trees in that Binary Tree.



##### It can be visualized as: 

![img-heap](https://www.techiedelight.com/wp-content/uploads/2016/11/Min-Max-Heap.png)

### Applications :

- It is used in Dijkstra's Shortest Path Algorithm using priority queue.
- It is used to implement Prim’s Algorithm to store keys of nodes and extract minimum key node at every step.
- It is used in Huffman codes which is used to compresses data.
- It is used in A* search algorithm which is used to find the shortest path between two vertices of a weighted graph.
- It is used in heap sort.Heap sort is typically implemented using Heap which is an implementation of Priority Queue.

#### Why using Heap to implement priority queue instead of maps?

A heap is sorted initially, Whenever we insert a new element, it just needs to iterate through the height of the tree 
in worst case which can be done in logarithmic time.
map is a red-black tree, so it takes O(N log N) time to insert the elements, keeping them sorted after each insertion. They are stored as linked nodes, so each item incurs malloc and free overhead. Then it takes O(N) time to iterate over them and destroy the structure.
Therefore,heaps are much faster as compare to maps.


### Design and Specifications :

There are 3 files , one is priority_queue.c which contains the implementation of the data structure ,other is Main.c file which contains driver function.And last file is heap.h contains Function declaration.
It can be included in Main.c by using "#include "heap.h"".

Here is description about priority_queue.c file :
Priority_queue.c file contains all the function of heap data structure . Using these functions we can insert an element, get minimum or maximum element or remove the minimum or maximum element or get size of priority queue.

| Function name | Description |                                                  
| :---: | :---: |
| allocate_memory_to_pq() | The function allocates memory to priority queue in such a way that every time priority queue is about to get full it doubles its size.|
|is_empty()| It checks if our priority queue is empty or not|
|front()| It returns the element according to their priority in our priority queue in O(1) time complexity.|
|push()| It inserts an element to our complete binary tree in such a way that it satisfies the properties of a complete binary tree. It completes this operation in logarithmic time i.e log(n) time complexity.|
|pop()| It removes the minimum/maximum element in heap. It is done by swapping last element with root of tree. Now end element is removed which is now current element to be removed and it arranges root in order to maintain order of Complete binary tree.|
|get_size()| It returns size of heap.|
   





