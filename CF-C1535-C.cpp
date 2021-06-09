/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;

int t, len, ans, lfq[maxn], dis[maxn]; 
string str;
void inits(){
    ans = 0;
    memset(lfq, 0, sizeof(lfq));
    memset(dis, 0, sizeof(dis));

    int pos = 1;
    while(pos <= len)
    {
        if(str[pos] == '?')
        {
            int nowpos = pos;
            while(str[pos] == '?')
                lfq[pos] = nowpos, pos++;
        }
        else    pos++;
    }
}
int calc(int nowrt){
    stack<char> s1;
    int nowpos = nowrt;
    s1.push(str[nowpos]); 
    nowpos++;
    while(nowpos <= len)
    {
        if(s1.top() != '?')
        {
            if(str[nowpos] == '?')
                s1.top() == '0' ? s1.push('1') : s1.push('0');
            else if(str[nowpos] != s1.top())
                s1.push(str[nowpos]);
            else
                break;
        }
        else
        {
            if(str[nowpos] == '?')
                s1.push(str[nowpos]);
            else if(str[nowpos] == '1')
                s1.pop(), s1.push('0'), s1.push('1');
            else
                s1.pop(), s1.push('1'), s1.push('0');
        }
        nowpos++;
    }
    return nowpos - 1;
}
signed main(void)
{
    //IO;
    cin >> t;
    while(t--)
    {
        cin >> str;
        str = "#" + str;
        len = str.length() - 1; inits();
        int now = 0, las = 1;
        for(int i = 1; i <= len; )
        {
            now = calc(las);
            int seqlen = now - i + 1;
            if(str[now] == '?')
            {
                int ri = i, g = 0;
                i = max(lfq[now], i + 1);
                las = now;
                if(i > len)    break;
                ans += (i - ri) * (i - ri + 1) / 2;
                //printf("debug1: ri:%lld i:%lld sq:%lld a:%lld\n", ri, i, seqlen, (i - ri + g) * (i - ri + 1 + g) / 2);
            }
            else
            {
                i = now + 1;
                las = i;
                ans += seqlen * (seqlen - 1) / 2;
                //printf("debug2: %lld %lld %lld %lld\n", i, now, seqlen, seqlen * (seqlen - 1) / 2);
            }
        }
        int pos = len;
        printf("%lld\n", ans + len);
    }
    return 0;
}