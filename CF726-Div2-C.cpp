/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 400005
#define int long long
using namespace std;
int t, n, h[maxn], vis[maxn], ans[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &h[i]), vis[i] = 0;
        sort(h + 1, h + n + 1);
        int minn = (1 << 30), f1 = -1, t1 = -1;
        for(int i = 1; i <= n - 1; i++)
            if(h[i + 1] - h[i] < minn)
            {
                minn = h[i + 1] - h[i];
                f1 = i, t1 = i + 1;
            }
        //printf("%d %d\n", f1, t1);
        vis[f1] = vis[t1] = 1;
        int cnt = 0;
        ans[++cnt] = h[f1];
        for(int i = 1; i <= n; i++)
            if(vis[i] == 0 && h[i] >= ans[cnt])
                ans[++cnt] = h[i], vis[i] = 1;
        for(int i = 1; i <= n; i++)
            if(vis[i] == 0)
                ans[++cnt] = h[i], vis[i] = 1;
        ans[++cnt] = h[t1];
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}
