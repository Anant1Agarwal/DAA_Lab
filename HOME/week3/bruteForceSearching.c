#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int opcount = 0;

int BruteForceStringMatch(char text[], char pat[])
{
    int n = strlen(text);
    int m = strlen(pat);
    for (int i = 0; i <=n - m; i++)
    {
        int j = 0;
        for (j; j < m; j++)
        {
            opcount++;
            if (pat[j] != text[i + j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char text[100];
    char pattern[20];
    printf("Enter Text: ");
    scanf("%[^\n]", text);

    getchar();

    printf("Enter pattern to be searched: ");
    scanf("%[^\n]", pattern);

    int found = BruteForceStringMatch(text, pattern);

    if (found!=-1)
    {
        printf("Pattern found at index %d", found);
    }
    else
    {
        printf("\nPattern NOT found. Error 404!");
    }
    printf("\nNo of operation count is %d", opcount);
}