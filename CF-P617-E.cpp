#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, k, siz;
int a[maxn], ans[maxn];
int pre[maxn], cnt[maxn];
struct Node{
    int l;
    int r;
    int id;
}Q[maxn];
bool cmp(const Node &A, const Node &B){
    int b1 = A.l / siz;
    int b2 = B.l / siz;
    if(b1 == b2)
        return b1 & 1 ? A.r < B.r : A.r > B.r;
    return b1 < b2;
}
int tot;
void add(int pos){
    
}
void del(int pos){

}
int main(void)
{
    scanf("%d %d %d", &n, &m, &k);
    siz = sqrt(n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] ^ a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }
    sort(Q + 1, Q + m + 1, cmp);
    int lf = 1, rt = 0;
    for(int i = 1; i <= m; i++)
    {
        while(lf < Q[i].l)    del(lf++);
        while(lf > Q[i].l)    add(--lf);
        while(rt < Q[i].r)    add(++rt);
        while(rt > Q[i].r)    del(rt--); 
        ans[Q[i].id] = tot;
    }
    for(int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
