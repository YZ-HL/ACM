/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct Node{
    int dep;
    int pre;
    int num;
    int pos;
}ans[maxn];
int t, n, a[maxn];
string prestr(int now){
    if(ans[now].dep == 0)
        return to_string(ans[now].num);
    return prestr(ans[now].pre) + "." + to_string(ans[now].num);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        stack<Node> s1;
        s1.push((Node){0, -1, a[1], 1});    ans[1] = s1.top();
        for(int i = 2; i <= n; i++)
        {
            Node nowtop = s1.top();
            if(a[i] == 1)
            {
                s1.push((Node){nowtop.dep + 1, nowtop.pos, a[i], i});
                ans[i] = s1.top();
            }
            else if(a[i] == nowtop.num + 1)
            {
                s1.push((Node){nowtop.dep, nowtop.pre, a[i], i});
                ans[i] = s1.top();
            }
            else
            {
                while(a[i] != s1.top().num + 1)
                {
                    int nowdep = s1.top().dep;
                    while(s1.top().dep == nowdep)    s1.pop();
                }
                nowtop = s1.top();
                s1.push({nowtop.dep, nowtop.pre, a[i], i});
                ans[i] = s1.top();
            }
        }
        for(int i = 1; i <= n; i++)
            cout << prestr(ans[i].pos) << '\n';
    }
    return 0;
}
