// Application memery 
// https://medium.com/@nickolasteixeira/stack-vs-heap-whats-the-difference-and-why-should-i-care-5abc78da1a88#:~:text=The%20stack%20is%20a%20segment,%2Dout%20(LIFO)%20manner.&text=The%20main%20function%20and%20all,stored%20in%20an%20initial%20frame.
/*                +-----> what decides the size of this container
     _____________|__
    |                |
    |                |
    |     HEAP       | --->it is a dynamic part of the memery and it grows downwards what if it overlaps the stack 
    | -------------  |      malloc(/free) and new methods operate on the heap
    |                |
    |   Fixed size   | 
    |                | ---> holds all the local variables local function 
    |     STACK      |
    | -------------  |
    |    Fixed size  |
    |                | ---> static or the global vars have lifetime throughout the whole code and 
    | STATIC/ GLOBAL |      all the information about the function call execution goes in here
    | ------------   |
    |   Fixed size   |    // cached LRU---> stack implementation..
    |                |  
    |    CODE        | 
    |                |
    |________________|

    Memory Leak Refers to the situation where we left unused data on the heap and do not free it.

 

*/

