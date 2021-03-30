#include <bits/stdc++.h>
const int maxn = 1e7 + 5;
using namespace std;
int t, n, k, ans, tra[maxn];
set<int> s1;
int cnt, pri[maxn];
bool isp[maxn];
void euler(int lim){
    memset(isp, true, sizeof(isp));
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])    pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)    break;
        }
    }
}
int conver(int x){
    if(isp[x])    return x;
    if(tra[x])    return tra[x];
    int bas = 1;
    for(int i = 2; i * i <= x; i++)
    {
        int cnt = 0;
        while(x % i == 0)
        {
            x /= i;
            cnt++;
        }
        if(cnt & 1)    bas *= i;
    }
    if(x > 1)   bas *= x;
    return tra[x] = bas;
}
int main(void)
{
    euler(maxn - 5);
    scanf("%d", &t);
    while(t--)
    {
        ans = 0; s1.clear();
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            tmp = conver(tmp);
            if(s1.count(tmp))
            {
                s1.clear();
                s1.insert(tmp);
                ans++;
                //printf("debug: %d\n", i);
            }
            else    s1.insert(tmp);
        }
        printf("%d\n", s1.size() ? ans + 1 : ans);
    }
    return 0;
}
