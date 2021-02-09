#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, k, h[maxn], w[maxn];
bool check(int now){
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int maxx = max(h[i], w[i]);
        int minn = min(h[i], w[i]);
        if(maxx < now)
            continue;
        cnt += (maxx / now) * (minn / now);
    }
    return cnt >= k;
}
int main(void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &h[i], &w[i]);
    int lf = 1, rt = 100000, ans = -1;
    while(lf <= rt)
    {
        int mid = (lf + rt) / 2;
        check(mid) ? ans = mid, lf = mid + 1 : rt = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
