/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int t, r1, s1, p1, r2, s2, p2;
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &r1, &p1, &s1);
        scanf("%lld %lld %lld", &r2, &p2, &s2);
        int ans = 0;
        int minn1 = min(r2, s1);
        r2 -= minn1; s1 -= minn1; ans += minn1;
        int minn2 = min(p2, r1);
        p2 -= minn2; r1 -= minn2; ans += minn2;
        int minn3 = min(s2, p1);
        s2 -= minn3; p1 -= minn3; ans += minn3;
        int minn4 = min(r1, r2); r1 -= minn4; r2 -= minn4;
        int minn5 = min(p1, p2); p1 -= minn5; p2 -= minn5;
        int minn6 = min(s1, s2); s1 -= minn6; s2 -= minn6;
        ans -= r2 + p2 + s2;
        printf("%lld\n", ans);          
    }
    return 0;
}
