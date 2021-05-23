#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, s[maxn], ans[maxn];
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &s[i]);
    int ans_minn = (1 << 30);
    
    sort(s + 1, s + n + 1);
    do{
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            int minn = (1 << 30), maxx = -(1 << 30);
            for(int j = 1; j <= i; j++)
            {
                minn = min(minn, s[j]);
                maxx = max(maxx, s[j]);
            }
            sum += maxx - minn;
        }
        //printf("/debug2: %lld %lld\n", ans_minn, sum);
        ans_minn = min(ans_minn, sum);
    }while(next_permutation(s + 1, s + n + 1));
    sort(s + 1, s + n + 1);
    do{
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            int minn = (1 << 30), maxx = -(1 << 30);
            for(int j = 1; j <= i; j++)
            {
                minn = min(minn, s[j]);
                maxx = max(maxx, s[j]);
            }
            sum += maxx - minn;
        }
        if(ans_minn == sum)
        {
            printf("debug: %lld \n", ans_minn);
            for(int i = 1; i <= n; i++)
                printf(i == n ? "%lld\n" : "%lld ", s[i]);
        }
    }while(next_permutation(s + 1, s + n + 1));
    return 0;
}
