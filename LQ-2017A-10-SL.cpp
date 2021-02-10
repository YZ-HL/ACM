//双倍经验 https://www.luogu.com.cn/problem/P5490
#include <bits/stdc++.h>
#define maxn 3000005
#define int long long
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
using namespace std;
int n, ans, tot, mp[maxn];
struct SegTree{
    int lf, rt;
    int sum, len;
} tree[maxn];
struct ScanLine{
    int lf, rt, h;
    int mark;
    bool operator < (const ScanLine &A) const{
        return h != A.h ? h < A.h : mark > A.mark;
    }
} SL[maxn];
void pushup(int now){
    if(tree[now].sum)
        tree[now].len = mp[tree[now].rt + 1] - mp[tree[now].lf];
    else
        tree[now].len = tree[lson(now)].len + tree[rson(now)].len;
}
void EditSeg(int now, int lf, int rt, int k){
    int nlf = mp[tree[now].lf], nrt = mp[tree[now].rt + 1];
    if(nlf >= rt || nrt <= lf)
        return;
    if(nlf >= lf && nrt <= rt)
    {
        tree[now].sum += k;
        pushup(now);
        return;
    }
    EditSeg(lson(now), lf, rt, k);
    EditSeg(rson(now), lf, rt, k);
    pushup(now);
}
void Build(int now, int lf, int rt){
    if(lf > rt)    return;
    tree[now].lf = lf;
    tree[now].rt = rt;
    tree[now].sum = 0;
    tree[now].len = 0;
    if(lf == rt)    return;
    int mid = (lf + rt) / 2;
    Build(lson(now), lf, mid);
    Build(rson(now), mid + 1, rt);
}
signed main(void)
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        int xx1, xx2, yy1, yy2;
        scanf("%lld %lld %lld %lld", &xx1, &yy1, &xx2, &yy2);
        if(xx1 > xx2)   swap(xx1, yy1);
        if(yy1 > yy2)   swap(yy1, yy2);
        if(xx1 == xx2 || yy1 == yy2)    continue;
        mp[i] = xx1;
        mp[i + n] = xx2;
        SL[i] = (ScanLine){xx1, xx2, yy1, 1};
        SL[i + n] = (ScanLine){xx1, xx2, yy2, -1};
    }
    n <<= 1;
    sort(mp + 1, mp + n + 1);
    sort(SL + 1, SL + n + 1);
    tot = unique(mp + 1, mp + n + 1) - mp - 1;
    Build(1, 1, tot - 1);
    for(int i = 1; i <= n - 1; i++)
    {
        EditSeg(1, SL[i].lf, SL[i].rt, SL[i].mark);
        ans += tree[1].len * (SL[i + 1].h - SL[i].h);
    }
    printf("%lld\n", ans);
    return 0;
}
