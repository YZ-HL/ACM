/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, dp[maxn];
int facnum(int val){
    int cnt = 0;
    for(int i = 2; i <= val - 1; i++)
        if(val % i == 0)    cnt++;
    return cnt;
}
int dfs(int x){
    if(x == 1 || x == 2)    return 0;
    if(~dp[x])              return dp[x];
    int val = 0;
    for(int i = 2; i <= x - 1; i++)
        if(x % i == 0)
            val |= (!dfs(x - i));
    return dp[x] = val;
}
int main(void)
{
    
    /*
    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= 128; i++)
        //if(dfs(i) == 1)    printf("%d,", i);
        printf("i:%d fn:%d dfs:%d\n", i, facnum(i), dfs(i));
    */
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n == 1 || n == 2 || n == 3)    printf("Bob\n");
        else if(n == 4)                   printf("Alice\n");
        else if(n & 1)                    printf("Bob\n");
        else
        {
            int r = n, cntt = 0;
            while(r % 2 == 0)    r /= 2, cntt++;
            if(r == 1)
                printf(cntt & 1 ? "Bob\n" : "Alice\n");
            else
                printf("Alice\n");
        }
    }
    return 0;
}
