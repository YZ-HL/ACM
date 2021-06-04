/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, flag;
int main(void)
{
    cin >> n;
    int lf = 1, rt = n;
    while(lf < rt)
    {
        if(rt - lf + 1 == 2)
        {
            cout << "? " << lf << " " << rt << endl;
            int ans;
            cin >> ans;
            cout << "! " << (ans == lf ? rt : lf) << endl;
            break;
        }
        int mid = (lf + rt) / 2;
        int pos1, pos2;
        cout << "? " << lf << " " << rt << endl;
        cin >> pos1;
        if(pos1 <= mid)
        {
            cout << "? " << lf << " " << mid << endl;
            cin >> pos2;
            if(pos1 == pos2)    rt = mid;
            else                lf = mid;
        }
        else
        {
            cout << "? " << mid << " " << rt << endl;
            cin >> pos2;
            if(pos1 == pos2)    lf = mid;
            else                rt = mid;
        }
    }
    return 0;
}
//5 1 4 2 3
//1 3 4 6 5 2