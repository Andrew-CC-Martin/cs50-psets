#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int first_digit = 0;
    int second_digit = 0;
    int digit_length = 0;

    long number = get_long("Number: ");
    long copy = number;

    while (copy)
    {
        digit_length += 1;
        copy /= 10;
    }

    int first_digit_index = digit_length - 1;
    int second_digit_index = digit_length - 2;

    copy = number;

    for (int i = 0; i < digit_length; i++)
    {
        if (i == first_digit_index)
        {
            first_digit = copy;
        }
        if (i == second_digit_index)
        {
            second_digit = copy % 10;
        }
        copy /= 10;
    }

    int total = 0;
    int digit_num_from_right = 1;
    while (number)
    {
        int current_digit = number % 10;

        if (digit_num_from_right % 2 == 0)
        {
            int current_doubled = current_digit * 2;
            while (current_doubled)
            {
                total += current_doubled % 10;
                current_doubled /= 10;
            }
        }
        else
        {
            total += current_digit;
        }
        digit_num_from_right += 1;
        number /= 10;
    }

    if (total % 10 == 0)
    {
        if ((digit_length == 13 || digit_length == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }

        else if (digit_length == 16 && first_digit == 5 && second_digit > 0 && second_digit < 6)
        {
            printf("MASTERCARD\n");
        }

        else if (digit_length == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
        {
            printf("AMEX\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}

