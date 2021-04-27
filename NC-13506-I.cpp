#include <bits/stdc++.h>
#define maxn 2000005
#define int long long
using namespace std;
int n;
int nxt[maxn];
vector<int> a;
/*
int kmp_pre(int m){
    int i, j;
    i = 0, j = nxt[0] = -1;
    while(i < m)
    {
        while(j != -1 && a[i] != a[j])    j = nxt[j];
        nxt[++i] = ++j;
    }
}
*/
void kmp_pre(){
    int j = 0,k = -1;
    nxt[0] = -1;
    while(j < n)
    {
        if(k == -1 || a[j] == a[k])
            nxt[++j] = ++k;
        else 
            k = nxt[k];
    }
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%lld", &tmp);
        a.push_back(tmp);
    }
    reverse(a.begin(), a.end());
    kmp_pre();
    int sum = (1 << 30), ansk, ansp;
    for(int i = 0; i < n; i++)
    {
        int nowp = i - nxt[i], nowk = n - i;
        //printf("debug: %d %d %d %d\n", i, nowp, nowk, nxt[i]);
        if(nowp + nowk < sum)
        {
            ansp = nowp;
            ansk = nowk;
            sum = ansk + ansp;
        }
        else if(nowp + nowk == sum && nowp < ansp)
        {
            ansp = nowp;
            ansk = nowk;
        }
    }
    printf("%lld %lld\n", ansk, ansp);
    return 0;
}
