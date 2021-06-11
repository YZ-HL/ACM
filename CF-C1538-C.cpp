/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 400005
#define int long long
using namespace std;
int t, n, l, r, a[maxn];
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &n, &l, &r);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        sort(a + 1, a + n + 1);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int pos1 = lower_bound(a + i + 1, a + n + 1, l - a[i]) - a;
            int pos2 = upper_bound(a + i + 1, a + n + 1, r - a[i]) - a - 1;
            //printf("debug: %lld %lld\n", pos1, pos2);
            ans += pos2 - pos1 + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
