/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        printf("%d\n", n * 3);
        for(int i = 1; i <= n; i += 2)
        {
            a[i] = a[i] + a[i + 1];
            printf("1 %d %d\n", i, i + 1);
            a[i + 1] = a[i + 1] - a[i];
            printf("2 %d %d\n", i, i + 1);
            a[i + 1] = a[i + 1] - a[i];
            printf("2 %d %d\n", i, i + 1);
            a[i] = a[i] + a[i + 1];
            printf("1 %d %d\n", i, i + 1);
            a[i + 1] = a[i + 1] - a[i];
            printf("2 %d %d\n", i, i + 1);
            a[i + 1] = a[i + 1] - a[i];
            printf("2 %d %d\n", i, i + 1);
            /*
            for(int j = 1; j <= n; j++)
                printf(j == n ? "%d\n" : "%d ", a[j]);
            */
        }

    }
    return 0;
}
