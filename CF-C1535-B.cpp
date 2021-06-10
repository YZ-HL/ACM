/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int t, n;
struct Node{
    int val;
    int dnum;
    int iseven;
}P[maxn];
int getNumber(int x){
    int cnt = 0;
    for(int i = 2; i * i <= x; i++)
    {
        while(x % i == 0)
        {
            x /= i;
            cnt++;
        }
    }
    if(x > 1)    cnt++;
    return cnt;
}
bool cmp(const Node &A, const Node &B){
    if(A.iseven != B.iseven)
        return A.iseven > B.iseven;
    return A.dnum < B.dnum;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int val;
            scanf("%d", &val);
            P[i].val = val;
            P[i].dnum = getNumber(val);
            P[i].iseven = (val % 2 == 0);
        }
        sort(P + 1, P + n + 1, cmp);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if(__gcd(P[i].val, 2 * P[j].val) > 1)
                    ans++;
        printf("%d\n", ans);
    }
    return 0;
}
