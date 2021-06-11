/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 400005
#define int long long
using namespace std;
int t, l, r;
int qpow(int a, int b){
    if(b == 0)    return 1;
    int tmp = qpow(a, b / 2);
    tmp = (tmp * tmp);
    if(b & 1)    tmp = (tmp * a);
    return tmp;
}
int calc(int l, int r){
    int sum = 0;
    for(int i = l + 1; i <= r; i++)
    {
        string las = to_string(i - 1);
        string now = to_string(i);
        int pos1 = las.length() - 1, pos2 = now.length() - 1, cnt = 0;
        while(pos1 >= 0 && pos2 >= 0)
        {
            if(las[pos1] != now[pos2])    cnt++;
            pos1--; pos2--;
        }
        cnt += abs(pos1 - pos2);
        sum += cnt;
    }
    return sum;
}
int query(int x){
    int cnt = 0, bas = 1, res = 0;
    while(x)
    {
        res += bas * (x % 10) - 1;
        x /= 10;
        bas = bas * 10 + 1;
        cnt++;
    }
    return res + cnt - 1;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", query(r) - query(l));
    }
    return 0;
}
