/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int t, n, q[maxn];
int ans1[maxn], ans2[maxn];
set<int> s1, s2;

void solve1(){
    int maxx = -1;
    for(int i = 1; i <= n; i++)
    {
        if(maxx < q[i])
        {
            maxx = q[i];
            ans1[i] = q[i];
            s1.erase(q[i]);
        }
        else
        {
            ans1[i] = *s1.begin();
            s1.erase(ans1[i]);
        }
    }
    for(int i = 1; i <= n; i++)
        printf(i == n ? "%d\n" : "%d ", ans1[i]);
}
void solve2(){
    int maxx = -1;
    for(int i = 1; i <= n; i++)
    {
        if(maxx < q[i])
        {
            maxx = q[i];
            ans2[i] = q[i];
            s2.erase(ans2[i]);
        }
        else
        {
            set<int, int>::iterator iter = s2.lower_bound(q[i]);
            iter--;
            ans2[i] = *iter;
            s2.erase(ans2[i]);   
        }
    }
    for(int i = 1; i <= n; i++)
        printf(i == n ? "%d\n" : "%d ", ans2[i]);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)   
        {
            scanf("%d", &q[i]);
            s1.insert(i); s2.insert(i); 
        }
        solve1();
        solve2();        
    }
    return 0;
}
