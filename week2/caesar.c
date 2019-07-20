#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]) % 26;
        string plaintext = get_string("plaintext: ");
        int j = strlen(plaintext);
        
        printf("ciphertext: ");
        
        for (int i = 0; i < j; i++)
        {
            if (isalpha(plaintext[i]))
            {
                int ascii_shift = isupper(plaintext[i]) ? 65 : 97;
                printf("%c", (((plaintext[i] - ascii_shift) + k) % 26) + ascii_shift);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
