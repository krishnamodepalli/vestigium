#include <stdio.h>

int T, N;
int y_o_n(int input[N]);
void main()
{
    scanf("%d", &T);
    int trace[T], rows[T], cols[T];
    for (int a = 0; a < T; a++)
    {
        scanf("%d", &N);
        int arr[N][N];
        for (int b = 0; b < N; b++)
        {
            for (int c = 0; c < N; c++)
                scanf("%d", &arr[b][c]);
        }
        int row[N], col[N];
        int r = 0, c = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                row[j] = arr[i][j];
                col[j] = arr[j][i];
            }
            if (y_o_n(row) == 1)
                r++;
            if (y_o_n(col) == 1)
                c++;
            else
                continue;
        }
        int k = 0;
        for (int l = 0; l < N; l++)
            k += arr[l][l];
        trace[a] = k;
        rows[a] = r;
        cols[a] = c;
    }
    printf("\n");
    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: %d %d %d\n", i + 1, trace[i], rows[i], cols[i]);
    }
}
int y_o_n(int input[N])
{
    for (int i = 0; i < N; i++)
    {
        int check = input[i];
        for (int j = i + 1; j < N; j++)
        {
            if (check == input[j])
                return 1;
            else
                continue;
        }
    }
    return 0;
}