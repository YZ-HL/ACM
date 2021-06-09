/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
string str;
set<string> s1;
string solve1(){
    for(int i = 0; i < 26; i++)
    {
        string res = "x";
        res[0] = (char)('a' + i);
        if(!s1.count(res))    return res;
    }
    return "GG";
}
string solve2(){
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
        {
            string res = "xx";
            res[0] = 'a' + i;
            res[1] = 'a' + j;
            //cout << "debug: " + res << '\n';
            if(!s1.count(res))    return res;
        }
    return "GG";
}
string solve3(){
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < 26; k++)
            {
                string res = "xxx";
                res[0] = (char)('a' + i);
                res[1] = (char)('a' + j);
                res[2] = (char)('a' + k);
                if(!s1.count(res))    return res;
            }
    return "GG";
}
int main(void)
{
    cin >> t;
    while(t--)
    {
        s1.clear();
        cin >> n;
        cin >> str;
        int len = str.length() - 1;
        for(int l = 1; l <= 3; l++)
            for(int i = 0; i <= len - l + 1; i++)
                s1.insert(str.substr(i, l));
        int flag = 0;
        string now = solve1();
        if(now != "GG")
            cout << now << '\n';
        else
        {
            now = solve2();
            if(now != "GG")
                cout << now << '\n';
            else
            {
                now = solve3();
                cout << now << '\n';
            }
        }
    }
    return 0;
}
