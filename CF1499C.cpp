/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 800005
#define int long long
using namespace std;

int t, n, c[maxn], sum[maxn], mino[maxn], mine[maxn];
signed main(void)
{
    scanf("%lld", &t);
    mine[0] = 1e17;
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &c[i]);
            sum[i] = sum[i - 1] + c[i];
            i & 1 ? mino[i] = (i == 1 ? c[i] : min(c[i], mino[i - 2])) : mine[i] = min(c[i], mine[i - 2]);
        }
        int ans = 1e17, nowcost;
        for(int i = 2; i <= n; i++)
        {
            if(i & 1)
            {
                int ost = ((i - 2) + 1) / 2;
                nowcost = mino[i] * (n - ost) + mine[i - 1] * (n - ost + 1);
                nowcost += sum[i] - mino[i] - mine[i - 1];
                ans = min(ans, nowcost);
                //printf("debug2: %lld %lld %lld %lld %lld\n", mino[i] * (n - ost) + mine[i - 1] * (n - ost + 1), mine[i - 1], mino[i], sum[i], nowcost);
            }
            else
            {
                int ost = (i - 2) / 2;
                nowcost = mino[i - 1] * (n - ost) + mine[i] * (n - ost);
                nowcost += sum[i] - mino[i - 1] - mine[i];
                ans = min(ans, nowcost); 
                //printf("debug1: %lld %lld %lld %lld\n", mino[i - 1], mine[i], sum[i], nowcost);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
