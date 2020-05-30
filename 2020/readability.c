#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main()
{
    float l = 0;
    float w = 1;
    float s = 0;
    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            l++;
        }

    // printf("Letters: %f\n", l);

    for (int i = 0; i < strlen(text); i++)
        if (text[i] == ' ')
        {
            w++;
        }

    // printf("Words: %f\n", w);

    for (int i = 0; i < strlen(text); i++)
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }

    // printf("Sentences: %f\n", s);

    float L = l / w * 100;
    float S = s / w * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(index));
    }
}
