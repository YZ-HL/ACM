#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, w, cnt;
int lg2n[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &w);
        cnt = n;
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            int bas = log2(tmp);
            lg2n[bas]++;
        }
        int ans = 0;
        while(cnt)
        {
            int nw = w;
            for(int i = 19; i >= 0; i--)
            {
                while(lg2n[i] && (int)pow(2, i) <= nw)
                {
                    nw -= (int)pow(2, i);
                    lg2n[i]--;
                    cnt--;
                }
            }
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
