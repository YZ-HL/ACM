#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int t, n, m, cnt[maxn], ans[maxn], flag;
vector<int> day[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        flag = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)    cnt[i] = 0;
        for(int i = 1; i <= m; i++)
        {
            day[i].clear();
            int k;
            scanf("%d", &k);
            for(int j = 1; j <= k; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                day[i].push_back(tmp);
            }
            ans[i] = day[i][0];
            cnt[day[i][0]]++;
            if(cnt[day[i][0]] > (m + 1) / 2)    flag = day[i][0];
        }
        if(!flag)
        {
            printf("YES\n");
            for(int i = 1; i <= m; i++)
                printf(i == m ? "%d\n" : "%d ", ans[i]);
        }
        else
        {
            for(int i = 1; i <= m; i++)
            {
                if(ans[i] == flag && day[i].size() > 1)
                {
                    ans[i] = day[i][1];
                    cnt[day[i][0]]--;
                }
                if(cnt[flag] <= (m + 1) / 2)    break;
            }
            if(cnt[flag] > (m + 1) / 2)
            { 
                printf("NO\n");
                continue;
            }
            else
            {
                printf("YES\n");
                for(int i = 1; i <= m; i++)
                    printf(i == m ? "%d\n" : "%d ", ans[i]);
            }
        }
    }
    return 0;
}
