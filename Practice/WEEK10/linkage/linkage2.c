#include <stdio.h>

extern int global; // Declaration of the global variable

int sub(void){
    global = 10; // Assign a value to the global variable
}