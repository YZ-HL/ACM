#include <bits/stdc++.h>
#define maxn 10000005
using namespace std;
int t, c;
int cnt, pri[maxn];
int s[maxn], psum[maxn];
bool isp[maxn];
void euler(int lim){
    s[1] = psum[1] = 1;
    memset(isp, true, sizeof(isp));
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])
        {
            pri[++cnt] = i;
            s[i] = psum[i] = i + 1;
        }
        for(int j = 1; j <= cnt && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)
            {
                psum[i * pri[j]] = pri[j] * psum[i] + 1;
                s[i * pri[j]] = s[i] / psum[i] * psum[i * pri[j]];
                break;
            }
            else
            {
                psum[i * pri[j]] = pri[j] + 1;
                s[i * pri[j]] = s[i] * s[pri[j]];
            }
        }
    }
}
unordered_map<int, int> mp;
int main(void)
{
    const int lim = 1e7;
    euler(lim);    
    for(int i = 1; i <= lim; i++)
    {
        if(!mp.count(s[i]))
            mp[s[i]] = i;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &c);
        if(mp.count(c))
            printf("%d\n", mp[c]);
        else
            printf("-1\n");
    }
    return 0;
}
