#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int n, xi[maxn], yi[maxn];
bool board[maxn][maxn];
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++)
        scanf("%d %d", &xi[i], &yi[i]), xi[i]++, yi[i]++;
    for(int k = 1; k <= 2 * n; k += 2)
    {
        if(xi[k] > xi[k + 1])   swap(xi[k], xi[k + 1]);
        if(yi[k] > yi[k + 1])   swap(yi[k], yi[k + 1]);

        for(int i = xi[k]; i <= xi[k + 1] - 1; i++)
            for(int j = yi[k]; j <= yi[k + 1] - 1; j++)
                board[i][j] = true;
    }    
    int cnt = 0;
    for(int i = 1; i <= maxn - 5; i++)
        for(int j = 1; j <= maxn - 5; j++)
            if(board[i][j])    cnt++;
    printf("%d\n", cnt);
    return 0;
}
