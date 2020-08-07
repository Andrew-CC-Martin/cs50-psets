#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);

    int letter_count = 0;
    int word_count = 1;
    int sentence_count = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;

        }

        if (text[i] > 64 && text[i] < 123)
        {
            letter_count++;
        }
    }

    int index = round(((5.88 * letter_count - 29.6 * sentence_count) / word_count) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}

