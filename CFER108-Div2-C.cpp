#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;
int t, n, maxx, ui[maxn], sum1[maxn], sum2[maxn], ansk[maxn];
vector<int> v1[maxn], v2[maxn];
signed main(void)
{
    //freopen("out.txt", "w", stdout);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &ui[i]);
            v1[i].clear(); v2[i].clear();
            sum1[i] = sum2[i] = ansk[i] = 0;
            maxx = 0;
        }
        
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%lld", &tmp);
            v1[ui[i]].push_back(tmp);
        }

        for(int i = 1; i <= n; i++)   
        {
            sort(v1[i].begin(), v1[i].end(), greater<int>());
            maxx = max(maxx, (int)v1[i].size());
        }

        for(int i = 1; i <= n; i++)
        {
            if(v1[i].empty())    continue;
            v2[i].push_back(0);
            for(int j = 0; j < v1[i].size(); j++)
                v2[i].push_back(v1[i][j] + v2[i][j]);
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < v2[i].size(); j++)
            {
                int r = j, siz = v2[i].size() - 1;
                ansk[r] += v2[i][siz - siz % r];
            }
        }

        for(int i = 1; i <= n; i++)
            printf("%lld ", ansk[i]);
        putchar('\n');
    }
    return 0;
}
