/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;

vector<int> v1;
void init(int lim){
    int cnt = 0;
    for(int i = 3; ; i += 2)
    {
        int res = i * i;
        int nowb = (res - 1) / 2;
        int nowc = nowb + 1;
        if(nowc > lim)    break;
        v1.push_back(nowc);
    }
}
int t, n;
signed main(void)
{
    const int lim = 1e9;
    init(lim);
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        int pos = lower_bound(v1.begin(), v1.end(), n) - v1.begin();
        if(v1[pos] == n)    pos++;
        //printf("debug: %d %d\n", v1[pos], pos);
        printf("%lld\n", pos);
    }
    return 0;
}
