#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")

#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#include <bits/stdc++.h>
#define maxn 200005
const int mod = 1e9 + 7;
using namespace std;

int ans = 1;
int n, q, a[maxn];

map<int, int> mp[maxn];
multiset<int> st[maxn];

long long qpow(long long a, int b, int p){
    if(!b)    return 1;
    long long tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)    tmp = (tmp * a) % p;
    return tmp;
}

long long inv(long long val){
    return qpow(val, mod - 2, mod);
}

void add(int pos, int num, int cp){
    if(st[num].size() == n)
    {
        ans = (ans * inv(qpow(num, *st[num].begin(), mod))) % mod;
        st[num].erase(st[num].find(mp[pos][num]));
        st[num].insert(mp[pos][num] + cp);
        mp[pos][num] += cp;
        ans = (ans * qpow(num, *st[num].begin(), mod)) % mod;
        return;
    }
    if(st[num].count(mp[pos][num]))    
        st[num].erase(st[num].find(mp[pos][num]));
    st[num].insert(cp + mp[pos][num]);
    if(st[num].size() == n)
        ans = (ans * qpow(num, *st[num].begin(), mod)) % mod;
    mp[pos][num] += cp;
}

void divv(int now, int pos){
    for(int i = 2; i * i <= now; i++)
    {
        int cnt = 0;
        while(now % i == 0)
            now /= i, cnt++;
        if(cnt)
            add(pos, i, cnt);
    }
    if(now > 1)
        add(pos, now, 1);
}

int main(void)
{
    IO;

    cin >> n >> q;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        divv(a[i], i);
    }
    for(int i = 1; i <= q; i++)
    {
        int pos, x;
        cin >> pos >> x;
        divv(x, pos);
        cout << ans << '\n';
    }
    return 0;
}