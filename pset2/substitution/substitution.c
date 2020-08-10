#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_upper(char c);
bool is_lower(char c);
void validate_key(string key);

int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc == 2)
    {
        validate_key(key);
    }

    else
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }

    string text = get_string("plaintext: \n");
    int length = strlen(text);

    int key_shift[26];
    for (int i = 0; i < 26; i++)
    {
        int char_num = (int) toupper(key[i]);

        key_shift[i] = char_num - 65 - i;
    }

    for (int i = 0; i < length; i++)
    {
        int char_num = (int) text[i];
        bool is_upper_case = is_upper(char_num);
        bool is_lower_case = is_lower(char_num);
        bool is_letter = is_upper_case || is_lower_case;

        int key_index;
        if (is_lower_case)
        {
            key_index = char_num - 97;
        }

        if (is_upper_case)
        {
            key_index = char_num - 65;
        }

        if (is_letter)
        {
            text[i] = text[i] + key_shift[key_index];
        }
    }
    printf("ciphertext: %s\n", text);
}

bool is_upper(char c)
{
    return c > 64 && c < 91;
}

bool is_lower(char c)
{
    return c > 96 && c < 123;
}

void validate_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }

    // Check if all chars in key are alphabetic and unique
    int used_letters[26] = { 0 };

    for (int i = 0; i < 26; i++)
    {
        bool is_upper_case = is_upper(key[i]);
        bool is_lower_case = is_lower(key[i]);

        int char_num = (int) key[i];

        if (is_lower_case)
        {
            int char_index = char_num - 97;
            used_letters[char_index] = 1;
        }

        if (is_upper_case)
        {
            int char_index = char_num - 65;

            used_letters[char_index] = 1;
        }

        bool is_letter = is_upper_case || is_lower_case;
        if (!is_letter)
        {
            exit(1);
        }
    }


    for (int i = 0; i < 26; i++)
    {
        if (!used_letters[i])
        {
            exit(1);
        }
    }
}

