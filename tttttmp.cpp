/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 200005
#define int long long 
using namespace std;
int n, k, x, p[maxn], s[maxn], t[maxn];
bool check(int val){
    int now = 0, ti = 0;
    for(int i = 0; i <= k; i++)
    {
        ti = t[i];
        int maxx = val * (p[i] - ti);
        if(now + maxx < x)    continue;
        if(i != k) 
            now += val * (t[i + 1] - ti);
        else
            now += maxx;
        //printf("debug: %lld %lld %lld %lld\n", i, now, ti, val);
    }
    return now >= x;
}
signed main(void)
{
    scanf("%lld %lld %lld %lld", &n, &k, &x, &p[0]);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &s[i]);
    for(int i = 1; i <= k; i++)
        scanf("%lld", &t[i]);
    for(int i = 1; i <= k; i++)
        scanf("%lld", &p[i]);
    sort(s + 1, s + n + 1);
    int lf = 1, rt = n, ans = 0;
    while(lf <= rt)
    {
        int mid = (lf + rt) / 2;
        check(s[mid]) ? ans = n - mid + 1, rt = mid - 1 : lf = mid + 1; 
    }
    printf("%lld\n", ans);
    return 0;
}
