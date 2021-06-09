/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;

int t, ans, dp[maxn][2];
string str;
signed main(void)
{
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> str;
        int len = str.length();    
        str = "#" + str;
        for(int i = 1; i <= len; i++)
        {
            if(str[i] == '?')
            {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else if(str[i] == '0')
            {
                dp[i][0] = 0;
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else
            {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = 0;
            }
            ans += max(dp[i][0], dp[i][1]);
        }
        cout << ans << '\n';    
    }
    return 0;
}