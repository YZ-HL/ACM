#include <bits/stdc++.h>
#define maxn 400005
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
#define INF (1 << 30)
using namespace std;
int n, m;
struct SegTree{
    int lf;
    int rt;
    int val;
    int lmax, rmax;
    SegTree() : lf(), rt(), val(), lmax(), rmax() {}
    SegTree(int lf, int rt, int val, int lmax, int rmax) : lf(lf), rt(rt), val(val), lmax(lmax), rmax(rmax) {}
} tree[maxn];
void Pushup(int now, SegTree t[]){
    t[now].val = t[lson(now)].val + t[rson(now)].val;

    t[now].lmax = t[lson(now)].lmax;
    if (t[lson(now)].rt - t[lson(now)].lf + 1 == t[lson(now)].lmax) 
        t[now].lmax = t[lson(now)].val + t[rson(now)].lmax;
    
    t[now].rmax = t[rson(now)].rmax;
    if (t[rson(now)].rt - t[rson(now)].lf + 1 == t[rson(now)].rmax) 
        t[now].rmax = t[rson(now)].val + t[lson(now)].rmax;
}
void Build(int now, int lf, int rt, SegTree t[]){
    t[now].lf = lf;
    t[now].rt = rt;
    if (lf == rt)
    {
        t[now].val = t[now].lmax = t[now].rmax = 1;
        return;
    }
    int mid = (lf + rt) / 2;
    Build(lson(now), lf, mid, t);
    Build(rson(now), mid + 1, rt, t);
    Pushup(now, t);
}
void Update(int now, int pos, int k, SegTree t[]){
    if (t[now].lf == pos && t[now].rt == pos)
    {
        t[now].lmax = t[now].rmax = k;
        return;
    }
    if (t[now].rt < pos || t[now].lf > pos)
    {
        return;
    }
    Update(lson(now), pos, k, t);
    Update(rson(now), pos, k, t);
    Pushup(now, t);
}
int Query(int now, int pos, SegTree t[]){
    if(t[now].lf == t[now].rt)
        return t[now].lmax + t[now].rmax;
    if (pos <= t[lson(now)].rt)
    {
        if(pos >= t[lson(now)].rt - t[lson(now)].rmax + 1)
            return t[lson(now)].rmax + t[rson(now)].lmax;
        else
            return Query(lson(now), pos, t);
    }
    else
    {
        if(pos <= t[rson(now)].lf + t[rson(now)].lmax - 1)
            return t[rson(now)].lmax + t[lson(now)].rmax;
        else
            return Query(rson(now), pos, t);
    }
}
char read(){
    char ch = getchar();
    while(ch != 'D' && ch != 'R' && ch != 'Q')  ch = getchar();
    return ch;
}
int main(void)
{
    while(~scanf("%d %d", &n, &m))
    {
        stack<int> s1;
        Build(1, 1, n, tree);
        for (int i = 1; i <= m; i++)
        {
            char ch = read();
            if (ch == 'D')
            {
                int p; scanf("%d", &p); s1.push(p);
                Update(1, p, 0, tree);
            }
            else if (ch == 'R')
            {
                int p = s1.top(); s1.pop();
                Update(1, p, 1, tree);
            }
            else 
            {
                int q; scanf("%d", &q);
                printf("%d\n", Query(1, q, tree));
            }
        }
    }
    return 0;
}