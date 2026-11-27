#include <stdio.h>

int set[20], subset[20];
int n, target;

void sumOfSubsets(int index, int currentSum, int subsetSize)
{
    int i;

    if (currentSum == target)
    {
        printf("Subset found: ");

        for (i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);

        printf("\n");
        return;
    }

    if (index == n || currentSum > target)
        return;

    /* Include current element */
    subset[subsetSize] = set[index];

    sumOfSubsets(
        index + 1,
        currentSum + set[index],
        subsetSize + 1
    );

    /* Exclude current element */
    sumOfSubsets(
        index + 1,
        currentSum,
        subsetSize
    );
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of the set:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d are:\n", target);

    sumOfSubsets(0, 0, 0);

    return 0;
}
