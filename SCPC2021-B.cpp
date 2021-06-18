/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int t, n, k, m, a[maxn], hav[maxn];
int hpc1[maxn], hpc2[maxn], ans[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &k, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), 
            ans[i] = hpc1[i] = hpc2[i] = hav[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(hav[a[i]] == 0)
                hav[a[i]] = 1;
            else
                hav[a[i]] = 0, hpc1[i]++;
        }
        for(int i = 1; i <= n; i++)
        {
            if(hav[a[i]] == 0)
                hav[a[i]] = 1;
            else
                hav[a[i]] = 0, hpc2[i]++;
        }
        int lop = m / (2 * n);
        
        for(int i = 1; i <= n; i++)
            ans[i] += lop * (hpc1[i] + hpc2[i]);

        if(m - lop * (2 * n) > 0)
        {
            int r = m - lop * (2 * n), rr = r - n;
            
            for(int i = 1; i <= min(n, r); i++)    ans[i] += hpc1[i];
            for(int i = 1; i <= rr; i++)    ans[i] += hpc2[i];
        }
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}