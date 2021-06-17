/* vegetable1024 | oi-liu.com | Maybe Lovely? */

#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx", "sse2")
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 2005
using namespace std;
int n, cnt, vis[maxn], d[maxn], in[maxn], lik[maxn][maxn];
vector<int> u, v;
struct Node{
    int pos;
    int dis;
}rr[maxn];
bool cmp(const Node &A, const Node &B){
    return A.dis < B.dis;
}
int main(void)
{
    cin >> n;
    int pos = 1;
    while(cnt != n - 1)
    {
        cout << "? " << pos << endl;
        for(int i = 1; i <= n; i++)    
        {
            cin >> d[i];
            if(d[i] == 1 && !lik[i][pos])
            {
                u.push_back(pos);
                v.push_back(i);
                lik[pos][i] = lik[i][pos] = 1;
                cnt++;
                in[pos]++; in[i]++;
            }
        }
        int r = 0;
        vis[pos] = 1;
        for(int i = 1; i <= n; i++)
            rr[++r] = (Node){i, d[i]};
        sort(rr + 1, rr + r + 1, cmp);
        map<int, int> ap;
        int maxx = 0, maxxp = 0;
        for(int i = 1; i <= n; i++)        
        {
            if(vis[rr[i].pos])    continue;
            ap[rr[i].dis]++;
            if(ap[rr[i].dis] > maxx)
            {
                maxx = ap[rr[i].dis];
                maxxp = rr[i].dis;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(vis[rr[i].pos])    continue;
            if(d[i] > maxxp)    break;
            pos = i;
        }
    }
    cout << "! " << endl;
    for(int i = 1; i <= n - 1; i++)
        cout << u[i - 1] <<  " " << v[i - 1] << endl;
    return 0;
}
