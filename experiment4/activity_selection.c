#include <stdio.h>

int main()
{
    int n, i, j;
    int start[20], finish[20];
    int temp, last;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start and finish time of activities:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &start[i], &finish[i]);
    }

    /* Sort activities according to finish time */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (finish[i] > finish[j])
            {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }

    printf("Selected activities are:\n");

    printf("(%d, %d)\n", start[0], finish[0]);
    last = 0;

    for (i = 1; i < n; i++)
    {
        if (start[i] >= finish[last])
        {
            printf("(%d, %d)\n", start[i], finish[i]);
            last = i;
        }
    }

    return 0;
}
