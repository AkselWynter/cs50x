// A short program that is a dynamic take on the 'hello world' program
// Takes in user input and welcomes the user

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}
