#include <stdio.h>
#include <limits.h>

void CalculateWorstFit(int b[], int m, int p[], int n)
{
    int alc[n];
    for (int i = 0; i < n; i++)
    {
        alc[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int max = INT_MIN;
        int max_index;
        for (int j = 0; j < m; j++)
        {
            if (p[i] <= b[j])
            {
                // alc[i] = j+1;
                if (b[j] - p[i] >= max)
                {
                    max = b[j] - p[i];
                    max_index = j;
                    alc[i] = max_index + 1;
                }
            }
        }
        b[max_index] = max;
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

    CalculateWorstFit(bsize, m, psize, n);
    return 0;
}