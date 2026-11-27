#include <stdio.h>

#define MAX 100

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    struct Item item[MAX], temp;
    int n, capacity;
    int i, j;
    int remainingCapacity;
    int greedyProfit = 0;
    int dp[MAX][MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits of items:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].weight, &item[i].profit);

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    /* Greedy Approach */

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    remainingCapacity = capacity;

    for (i = 0; i < n; i++)
    {
        if (item[i].weight <= remainingCapacity)
        {
            remainingCapacity -= item[i].weight;
            greedyProfit += item[i].profit;
        }
    }

    printf("\nMaximum profit using Greedy = %d\n",
           greedyProfit);

    /* Dynamic Programming Approach */

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (item[i - 1].weight <= j)
            {
                dp[i][j] = max(
                    item[i - 1].profit +
                    dp[i - 1][j - item[i - 1].weight],
                    dp[i - 1][j]
                );
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("Maximum profit using Dynamic Programming = %d\n",
           dp[n][capacity]);

    return 0;
}
