#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // get user's credit card number to validate
    long credit_card = get_long("Number: ");
    
    // find number of digits, and first & second digits in the provided credit card number
    int num_digits = 1, digit1 = 0, digit2 = 0, even_sum = 0, odd_sum = 0;
    
    while (credit_card > 0)
    {
        digit2 = digit1;
        digit1 = credit_card % 10;
        if (num_digits % 2 == 0)
        {
            int doubled = digit1 * 2;
            even_sum += ((doubled % 10) + (doubled / 10));
        }
        else
        {
            odd_sum += digit1;
        }
        // drop last digit from card number and increment the number of digits processed
        credit_card /= 10;
        num_digits++;
    }
    // num_digits was initialised as 1 so that the even/odd check made logical sense
    // when working 'backwards' through the digits, however this means that the resulting
    // variable is one two high
    num_digits--;
    
    // luhn test
    bool luhn = (even_sum + odd_sum) % 10 == 0;

    // test card number for each of the three sets of criteria to determine if it is valid
    if (luhn && num_digits == 13 && digit1 == 4)
    {
        printf("VISA\n");
    }
    else if (luhn && num_digits == 15 && digit1 == 3 && (digit2 == 4 || digit2 == 7))
    {
        printf("AMEX\n");
    }
    else if (luhn && num_digits == 16 && (digit1 == 5 && (digit2 > 0 && digit2 < 6)))
    {
        printf("MASTERCARD\n");
    }
    else if (luhn && num_digits == 16 && digit1 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
