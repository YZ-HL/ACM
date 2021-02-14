#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, k, maxx, a[maxn];
vector<int> v1[maxn];
int main(void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        v1[a[i] % k].push_back(a[i]);
    }
    for(int i = 0; i <= k - 1; i++)    sort(v1[i].begin(), v1[i].end());
    for(int i = 0; i <= k - 1; i++)
    {
        for(int j = 0; j <= k - 1; j++)
        {
            int r = ((k - i - j) + k) % k;
            int flag1, flag2, pos1, pos2;
            
            pos1 = v1[i].size(); pos2 = v1[j].size();
            
            if(i == j && v1[i].size() >= 2)
                flag1 = v1[i][pos1 - 1], flag2 = v1[j][pos2 - 2];
            else if(v1[i].size() && v1[j].size())
                flag1 = v1[i][pos1 - 1], flag2 = v1[j][pos2 - 1];
            else
                continue;
                
            int r1 = flag1, r2 = flag2;
            
            for(int l = v1[r].size() - 1; l >= 0; l--)
            {
                if(v1[r][l] == flag1)       flag1 = -1;
                else if(v1[r][l] == flag2)  flag2 = -1;
                else
                {
                    maxx = max(maxx, v1[r][l] + r1 + r2);
                    break;
                }               
            }
        }
    }
    printf("%d\n", maxx);
    return 0;
}
