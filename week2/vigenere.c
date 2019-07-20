#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool check_valid(string keyword)

int main(int argc, string argv[])
{
    // check that the correct number of cmd line arguments have been provided
    // and that the provided keyword is valid
    if (argc != 2 || !check_valid(argv[1]))
    {
        printf("Usage: ./viginere keyword\n");
        return 1;
    }
    
    string keyword = argv[1];
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        // check if each char of the plaintext is a letter and needs shifting
        // or is non-alpha i.e. punctuation
        if (isalpha(plaintext[i]))
        {
            int ascii_shift = isupper(plaintext[i]) ? 65 : 97;
            
            // set current shift key based on the current letter in the keyword
            // looping back to the beginning if plaintext is longer than the keyword
            int k = toupper(keyword[j % strlen(keyword)]) - 65;
            
            // shift the current letter of the plaintext by the shift key and adjust
            // depending on whether the char is upper or lowercase
            printf("%c", (((plaintext[i] - ascii_shift) + k) % 26) + ascii_shift);  
            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

// check that the keyword provided is valid (all elements are letters not numbers etc)
bool check_valid(string keyword)
{
    for (int i = 0; i < strlen(keyword); i++)
    {
        if (!isalpha(keyword[i]))
        {
            return false;
        }
    }
    return true;
}
