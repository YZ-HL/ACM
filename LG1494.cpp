#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, m, siz, c[maxn], ans1[maxn], ans2[maxn];
struct Node{
    int l;
    int r;
    int id;
} Q[maxn];
bool cmp(const Node &A, const Node &B){
    int b1 = A.l / siz;
    int b2 = B.l / siz;
    if(b1 != b2)
        return b1 < b2;
    return b1 & 1 ? A.r < B.r : A.r > B.r;
}
int tot = 0, cnt[maxn];
void add(int pos){
    //printf("debug: %lld\n", pos);
    tot -= cnt[c[pos]] * cnt[c[pos]];
    cnt[c[pos]]++;
    tot += cnt[c[pos]] * cnt[c[pos]];
}
void del(int pos){
    //printf("debug: %lld\n", pos);
    tot -= cnt[c[pos]] * cnt[c[pos]];
    cnt[c[pos]]--;
    tot += cnt[c[pos]] * cnt[c[pos]];
}
signed main(void)
{
    scanf("%lld %lld", &n, &m);
    siz = sqrt(n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &c[i]);
    for(int i = 1; i <= m; i++)
    {
        scanf("%lld %lld", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }  
    sort(Q + 1, Q + m + 1, cmp);  
    //printf("gg3");
    int l = 1, r = 0;
    for(int i = 1; i <= m; i++)
    {
        if(Q[i].l == Q[i].r)
        {
            ans1[Q[i].id] = 0; 
            ans2[Q[i].id] = 1;
            continue;
        }
        //printf("gg1");
        while(l < Q[i].l)    del(l++);
        while(r < Q[i].r)    add(++r);
        while(l > Q[i].l)    add(--l);
        while(r > Q[i].r)    del(r--);
        //printf("gg2");
        int num1 = tot - (Q[i].r - Q[i].l + 1);
        int num2 = (Q[i].r - Q[i].l) * (Q[i].r - Q[i].l + 1);
        int bas = __gcd(num1, num2);
        num1 /= bas;
        num2 /= bas;
        //printf("%lld/%lld\n", num1, num2);
        ans1[Q[i].id] = num1; 
        ans2[Q[i].id] = num2;
    }
    for(int i = 1; i <= m; i++)
        printf("%lld/%lld\n", ans1[i], ans2[i]);
    return 0;
}
