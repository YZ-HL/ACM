/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
long long t, n, sx, sy, nx[maxn], ny[maxn];
int main(void)
{
    //freopen("debug.txt", "w", stdout);
    scanf("%lld", &t);
    while(t--)
    {
        sx = 0; sy = 0;
        bool onex = true, oney = true;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld %lld", &nx[i], &ny[i]);
            sx += nx[i]; sy += ny[i];
        }
        if(n & 1)
        {
            printf("%d\n", 1);
            continue;
        }
        sort(nx + 1, nx + n + 1);
        sort(ny + 1, ny + n + 1);
        long long numx = nx[n / 2 + 1] - nx[n / 2] + 1;
        long long numy = ny[n / 2 + 1] - ny[n / 2] + 1;
        printf("%lld\n", numx * numy);
    }
    return 0;
}
