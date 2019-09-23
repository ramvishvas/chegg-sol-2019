#include <stdio.h>
#include <string.h>
// maximum legth of string is N ie 10
#define N 10
// maximum number of total string is M ie 10
#define M 10
int main()
{
    char name[M][N], *temp;
    int num;

    // take number of string
    printf("Enter the number of names you want to enter(< 11): ");
    scanf("%d", &num);

    // take num number of string as input
    for (int i = 0; i < num; i++)
    {
        printf("Enter %d Word: ", i + 1);
        scanf("%s", name[i]);
    }
    // print before sorting
    printf("Befor sorting:\t");
    for (int i = 0; i < num; i++)
    {
        printf("%s  ", name[i]);
    }

    // sotring main logic
    for (int j = 0; j < (num - 1); j++)
    {
        for (int k = 0; k < (num - 1 - j); k++)
        {
            if (strlen(name[k]) > strlen(name[k + 1]))
            {
                strcpy(temp, name[k]);
                strcpy(name[k], name[k + 1]);
                strcpy(name[k + 1], temp);
            }
        }
    }
    // print after sotring
    printf("\n\nAfter sorting:\t");
    for (int i = 0; i < num; i++)
    {
        printf("%s ", name[i]);
    }
    printf("\n");
    return 0;
}