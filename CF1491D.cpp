/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int q, u, v;
int lowbit(int x){
    return x & (-x);
}
int cntit(int x){
    int cnt = 0;
    while(x)
        x -= lowbit(x), cnt++;
    return cnt;
}
int main(void)
{
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &u, &v);
        if(u > v)
        {
            printf("NO\n");
            continue;
        }
        int cnt1 = cntit(u);
        int cnt2 = cntit(v);
        if(cnt2 < cnt1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        /*
        int bas = 0, ct1 = 0, ct2 = 0, flag = 1;
        while(bas < 30)
        {
            if(u & (1 << bas))    ct1++;
            if(v & (1 << bas))    ct2++;
            bas++;
            if(ct1 > )
        }
        */
    }
    return 0;
}
