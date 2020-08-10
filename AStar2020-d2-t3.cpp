#include <bits/stdc++.h>
#define maxn 20005
using namespace std;
int t, n;
int len[maxn], flag[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        vector<int> tp[105][15];
        memset(flag, 0, sizeof(flag));
        
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &len[i]);
            for (int j = 1; j <= len[i]; j++)
            {
                int tt, p;
                scanf("%d %d", &tt, &p);
                tp[tt][p].push_back(i);
            }
        }
        flag[1] = 1;
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                if(tp[i][j].size() <= 1)    continue;
                bool isY = false;
                for (int k = 0; k <= tp[i][j].size() - 1; k++)
                {
                    if(flag[tp[i][j][k]])
                    {
                        isY = true;
                        break;
                    }
                }
                if(isY)
                {
                    //printf("DEBUG: i:%d j:%d\n", i, j);
                    for (int k = 0; k <= tp[i][j].size() - 1; k++)  
                        flag[tp[i][j][k]] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (flag[i])    cnt++;
        for (int i = 1; i <= n; i++)
        {
            if (flag[i])
                --cnt, printf((cnt ? "%d " : "%d\n"), i);
        }
        //putchar('\n');
    }
    system("pause");
    return 0;
}