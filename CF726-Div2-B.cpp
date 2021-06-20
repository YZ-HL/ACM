/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, m, i, j;
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &n, &m, &i, &j);
        int mid1 = n / 2, mid2 = m / 2;
        if(i <= mid1 && j <= mid2)
            printf("%d %d %d %d\n", n, m, 1, 1);
        else if(i <= mid1 && j > mid2)
            printf("%d %d %d %d\n", n, 1, 1, m);
        else if(i > mid1 && j <= mid2)
            printf("%d %d %d %d\n", 1, m, n, 1);
        else
            printf("%d %d %d %d\n", 1, 1, n, m);
    }
    return 0;
}
