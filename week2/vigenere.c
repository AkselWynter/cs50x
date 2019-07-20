#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// add function to check if keyword argument is alpha
bool check_validity(string keyword)
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

int main(int argc, string argv[])
{
    if (argc != 2 || !check_validity(argv[1]))
    {
        printf("Usage: ./viginere keyword\n");
        return 1;
    }
    
    string keyword = argv[1];
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            int ascii_shift = isupper(plaintext[i]) ? 65 : 97;
            int k = toupper(keyword[j % strlen(keyword)]) - 65;
            
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
