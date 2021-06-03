/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int t, n, a[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        map<int, int> mp, cnt, setcnt;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            mp[a[i]]++;
        }
        for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)    
        {
            cnt[(*iter).second] += (*iter).second;
            setcnt[(*iter).second]++;
        }
        int del = 0, ans = (1 << 30), allset = mp.size();
        while(!cnt.empty())
        {
            map<int, int>::iterator iter = cnt.begin();
            int now = (*iter).first;
            int siz = (*iter).second;
            cnt.erase(now);
            allset -= setcnt[now];
            ans = min(ans, n - siz - now * allset + del);
            //printf("debug: %d %d %d\n", now, siz, n - siz - now * allset + del);
            //system("pause");
            del += siz;
            n -= siz;
        }
        printf("%d\n", ans);
    }
    return 0;
}
