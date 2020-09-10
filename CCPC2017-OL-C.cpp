#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define maxn 10
using namespace std;
int n, flag, up[maxn][maxn];
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        flag = 0;
        memset(up, 0, sizeof(up));

        scanf("%d", &n);
        for(int i = 1; i <= n - 1; i++)
            for(int j = i + 1; j <= n; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                if(n < 6 && tmp)
                    up[i][j] = up[j][i] = 1;
            }
        if(n < 6)
            for(int i = 1; i <= n; i++)
                for(int j = i+1; j <= n; j++)
                    for(int k = j+1; k <= n; k++)
                    {
                        if(up[i][j] && up[j][k] && up[i][k])
                            flag = 1;
                        if(!up[i][j] && !up[j][k] && !up[i][k])
                            flag = 1;
                    }

        printf(flag || n >= 6 ? "Bad Team!\n" : "Great Team!\n");
    }
    system("pause");
    return 0;
}
