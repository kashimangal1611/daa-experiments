#include <stdio.h>
#include <limits.h>

int m[20][20], s[20][20];

void printOptimal(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");
    printOptimal(i, s[i][j]);
    printOptimal(s[i][j] + 1, j);
    printf(")");
}

int main()
{
    int p[20];
    int n, i, j, k, L;
    int q;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions:\n");
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n]);

    printf("Optimal Parenthesization: ");
    printOptimal(1, n);

    printf("\n");

    return 0;
}
