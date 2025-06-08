#include <stdio.h>

int global;
extern int sub(void); // Declaration of the function

int main(void){
    sub(); // Call the function
    printf("global = %d\n", global); // Print the value of the global variable
}