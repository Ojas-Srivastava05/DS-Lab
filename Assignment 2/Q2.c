#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct question2
{
    int *ptr1;
    int *ptr2;
} ques;

int main()
{
    int n1;
    printf("ENTER THE NUMBER OF ELEMENTS IN ARRAY ");
    scanf("%d", &n1);

    int *arr1 = (int *)malloc(n1 * sizeof(int));
    int *arr2 = (int *)malloc(n1 * sizeof(int));

    if (arr1 == NULL || arr2 == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    ques.ptr1 = arr1;
    ques.ptr2 = arr2;

    printf("ENTER THE ELEMENTS OF ARRAY ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", ques.ptr1 + i);
    }

    for (int i = 0; i < n1; i++)
    {
        *(ques.ptr2 + i) = *(ques.ptr1 + i);
    }

    for (int i = 0; i < n1; i++)
    {
        if (i % 2 == 1)
        {
            if (i > 0 && i < n1 - 1)
            {
                arr2[i] = *(ques.ptr2 + i - 1) * *(ques.ptr2 + i + 1);
            }
        }
    }

    for (int i = 0; i < n1; i++)
    {
        printf("%d ", *(ques.ptr2 + i));
    }

    free(arr1);
    free(arr2);

    return 0;
}
