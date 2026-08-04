#include <stdio.h>
#include <stdlib.h>

struct SparseMatrix
{
    int row;
    int col;
    int val;
};

int main()
{
    int n;

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &n);

    struct SparseMatrix sm[n + 1], tsm[n + 1];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &sm[0].row, &sm[0].col);

    sm[0].val = n;

    printf("Enter the non-zero elements (row column value):\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d",
              &sm[i].row,
              &sm[i].col,
              &sm[i].val);
    }

    /* Header of transpose matrix */
    tsm[0].row = sm[0].col;
    tsm[0].col = sm[0].row;
    tsm[0].val = sm[0].val;

    /* Count number of elements in each column */
    int *row_term = (int *)calloc(sm[0].col, sizeof(int));

    for (int i = 1; i <= n; i++)
        row_term[sm[i].col]++;

    /* Starting position of each column */
    int *start_pos = (int *)calloc(sm[0].col, sizeof(int));

    start_pos[0] = 1;

    for (int i = 1; i < sm[0].col; i++)
        start_pos[i] = start_pos[i - 1] + row_term[i - 1];

    /* Fast transpose */
    for (int i = 1; i <= n; i++)
    {
        int j = start_pos[sm[i].col]++;

        tsm[j].row = sm[i].col;
        tsm[j].col = sm[i].row;
        tsm[j].val = sm[i].val;
    }

    printf("\nTranspose Sparse Matrix:\n");
    printf("Row\tCol\tValue\n");

    for (int i = 0; i <= tsm[0].val; i++)
    {
        printf("%d\t%d\t%d\n",
               tsm[i].row,
               tsm[i].col,
               tsm[i].val);
    }

    free(row_term);
    free(start_pos);

    return 0;
}