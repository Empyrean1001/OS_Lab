#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m];
    printf("Enter the allocation matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("For process %d: ", i + 1);
            scanf("%d", &alloc[i][j]);
        }
    }
    int max[n][m];
    printf("Enter the maximum matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("For process %d: ", i + 1);
            scanf("%d", &max[i][j]);
        }
    }
    int avail[m];
    printf("Enter the available resources: \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    printf("\n");
    printf("ALLOCATION MATRIX:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", alloc[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");
    printf("MAX MATRIX:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", max[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");
    printf("Available Resources:\n");
    for (int j = 0; j < m; j++)
    {
        printf("%d\t", avail[j]);
        printf(" ");
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("\n\n");
    printf("NEED MATRIX:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", need[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("\n\nThe following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("\n");
        printf("\nThe following is the Safe Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf("P%d ->", ans[i]);
        printf("P%d", ans[n - 1]);
    }
    return 0;
}