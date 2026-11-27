#include <stdio.h>

#define MAX 100

int n, capacity;
int weight[MAX], profit[MAX];
int maxProfitBT = 0;

/* Backtracking Approach */
void backtracking(int index, int currentWeight, int currentProfit)
{
    if (currentWeight > capacity)
        return;

    if (index == n)
    {
        if (currentProfit > maxProfitBT)
            maxProfitBT = currentProfit;

        return;
    }

    /* Include current item */
    backtracking(index + 1,
                 currentWeight + weight[index],
                 currentProfit + profit[index]);

    /* Exclude current item */
    backtracking(index + 1,
                 currentWeight,
                 currentProfit);
}

/* Branch and Bound Approach */
int branchAndBound()
{
    int i;
    int currentWeight = 0;
    int currentProfit = 0;

    for (i = 0; i < n; i++)
    {
        if (currentWeight + weight[i] <= capacity)
        {
            currentWeight += weight[i];
            currentProfit += profit[i];
        }
    }

    return currentProfit;
}

/* Dynamic Programming Approach */
int dynamicProgramming()
{
    int dp[MAX][MAX];
    int i, w;

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                int include = profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits of items:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &weight[i], &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    backtracking(0, 0, 0);

    printf("\nMaximum Profit using Backtracking = %d\n",
           maxProfitBT);

    printf("Maximum Profit using Branch and Bound = %d\n",
           branchAndBound());

    printf("Maximum Profit using Dynamic Programming = %d\n",
           dynamicProgramming());

    return 0;
}
