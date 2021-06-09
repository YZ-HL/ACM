/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int t, n;
string str;
int main(void)
{
    IO;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str;
        int len = str.length();
        int numD = 0, numK = 0;
        map<pair<int, int>, int> mp;
        for(int i = 0; i < len; i++)
        {
            str[i] == 'D' ? numD++ : numK++;
            int nowgcd = __gcd(numD, numK);
            mp[make_pair(numD / nowgcd, numK / nowgcd)]++;
            printf("%d ", mp[make_pair(numD / nowgcd, numK / nowgcd)]);
        }
        putchar('\n');
    }
    return 0;
}
