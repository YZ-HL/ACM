/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t;
string str;
int main(void)
{
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> str;
        int len = str.length();
        if(str.find("chimasu", len - 7) != string::npos)
            cout << str.substr(0, len - 7) + "tte" << '\n';

        else if(str.find("rimasu", len - 6) != string::npos)
            cout << str.substr(0, len - 6) + "tte" << '\n';

        else if(str.find("mimasu", len - 6) != string::npos)
            cout << str.substr(0, len - 6) + "nde" << '\n';
        
        else if(str.find("bimasu", len - 6) != string::npos)
            cout << str.substr(0, len - 6) + "nde" << '\n';
        
        else if(str.find("nimasu", len - 6) != string::npos)
            cout << str.substr(0, len - 6) + "nde" << '\n';

        else if(str == "ikimasu")
            cout << "itte" << '\n';
        
        else if(str.find("kimasu", len - 6) != string::npos)
            cout << str.substr(0, len - 6) + "ite" << '\n';
        
        else if(str.find("gimasu", len - 6) != string::npos)
            cout << str.substr(0, len - 6) + "ide" << '\n';

        else if(str.find("shimasu", len - 7) != string::npos)
            cout << str.substr(0, len - 7) + "shite" << '\n';
    }
    return 0;
}