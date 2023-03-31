#include <stdio.h>
#include <limits.h>

void CalculateBestFit(int b[], int m, int p[], int n)
{
    int alc[n];
    for (int i = 0; i < n; i++)
    {
        alc[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        int min_index;
        for (int j = 0; j < m; j++)
        {
            if (p[i] <= b[j])
            {
                // alc[i] = j+1;
                if (b[j] - p[i] < min)
                {
                    min = b[j] - p[i];
                    min_index = j;
                    alc[i] = min_index + 1;
                }
            }
        }
        b[min_index] = b[min_index] - p[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (alc[i] != -1)
            printf("process number-%d\t allocated block-%d\n", i + 1, alc[i]);
        else
            printf("process number-%d\t allocated block-not allocated\n", i + 1);
    }
}

int main()
{
    int m, n;
    printf("Enter the number of blocks in the memory: ");
    scanf("%d", &m);
    int bsize[m];
    printf("Enter the sizes for the memory segmentation: \n");
    for (int i = 0; i < m; i++)
    {
        printf("size of block %d: ", i + 1);
        scanf("%d", &bsize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int psize[n];
    printf("Enter the sizes of the processes to be allocated: \n");
    for (int i = 0; i < n; i++)
    {
        printf("size of process %d: ", i + 1);
        scanf("%d", &psize[i]);
    }

    CalculateBestFit(bsize, m, psize, n);
    return 0;
}