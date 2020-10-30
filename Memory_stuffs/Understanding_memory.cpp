// Application memery 
/*                +-----> what decides the size of this container
     _____________|__
    |                |
    |                |
    |    HEAP        | --->it is a dynamic part of the memery and it grows downwards what if it overlaps the stack 
    | -------------  |      malloc(/free) and new methods operate on the heap
    |                |
    |   Fixed size   | 
    |                | ---> holds all the local variables
    |     STACK      |
    | -------------  |
    |    Fixed size  |
    |                | ---> static or the global vars have lifetime throughout the whole code
    | STATIC/ GLOBAL |
    | ------------   |
    |   Fixed size   |
    |                |
    |    CODE        | --->
    |                |
    |________________|

    Memory Leak Refers to the situation where we left unused data on the heap and do not free it.



*/

