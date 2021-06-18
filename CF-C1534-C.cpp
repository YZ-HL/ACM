/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 800005
#define int long long

using namespace std;
int t, n, a[maxn], b[maxn];
int uset[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unioon(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy)    return;
    uset[fx] = fy;
}
const int mod = 1e9 + 7;
int qpow(int a, int b){
    if(b == 0)
        return 1;
    int tmp = qpow(a, b / 2);
    tmp = (tmp * tmp) % mod;
    if(b & 1)
        tmp = (tmp * a) % mod;
    return tmp;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            uset[i] = i;
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &b[i]);
            unioon(a[i], b[i]);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(find(i) == i)
                cnt++;
        int ans = qpow(2, cnt);
        printf("%lld\n", ans);
        
    }
    return 0;
}