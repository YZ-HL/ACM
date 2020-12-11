#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, pre[maxn], ans[maxn];
struct SegTree{
    int lf;
    int rt;
    int len;
} tree[maxn];
void Build(int lf, int rt, int now){
    tree[now].lf = lf;
    tree[now].rt = rt;
    tree[now].len = rt - lf + 1;
    if(lf == rt)    return;
    int mid = (lf + rt) / 2;
    Build(lf, mid, now << 1);
    Build(mid + 1, rt, (now << 1) + 1);
}
int Query(int now, int pos){
    tree[now].len--;
    if(tree[now].lf == tree[now].rt)    return tree[now].lf;
    return tree[now << 1].len >= pos ? Query(now << 1, pos) : Query((now << 1) + 1, pos - tree[now << 1].len);
}
int main(void)
{
    scanf("%d", &n);
    Build(1, n, 1);
    for(int i = 2; i <= n; i++)    scanf("%d", &pre[i]);
    for(int i = n; i >= 1; i--)    ans[i] = Query(1, pre[i] + 1);
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
