/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n, k, cnt, ans[maxn];
int main(void)
{
    scanf("%d %d", &n, &k);
    if(n <= k)
    {
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%d" : "%d ", i);
        return 0;
    }
    set<int> s1;
    for(int i = 1; i <= n; i++)    s1.insert(i);
    while(!s1.empty())
    {
        int minn = *s1.begin();
        for(int i = minn; i <= n; i += k)
            ans[++cnt] = i, s1.erase(i);
    }
    for(int i = 1; i <= n; i++)
        printf(i == n ? "%d" : "%d ", ans[i]);
    return 0;
}