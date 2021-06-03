/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 400005
using namespace std;

int n, m, minn[maxn], maxx[maxn];
string s, t;
int main(void)
{
    IO;
    cin >> n >> m;
    cin >> s >> t;
    s = "#" + s; t = "#" + t;
    int nowpos = 1;
    for(int i = 1; i <= n && nowpos <= m; i++)
        if(s[i] == t[nowpos])
            minn[nowpos++] = i;
    nowpos = m;
    for(int i = n; i >= 1 && nowpos <= m; i--)
        if(s[i] == t[nowpos])
            maxx[nowpos--] = i;
    int ans = 0;
    for(int i = m; i > 1; i--)
        ans = max(ans, maxx[i] - minn[i - 1]);
    cout << ans << '\n';
    return 0;
}
