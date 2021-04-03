#include <bits/stdc++.h>
#define maxn 100005
#define lson(x) (x << 1)
#define rson(x) (x << 1) + 1
using namespace std;
int n, cnt, a[maxn], tree[maxn];
void Build(int x){
    if(x > n)   return;
    Build(lson(x));
    Build(rson(x));
    tree[x] = a[++cnt];
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Build(1);
    for(int i = 1; i <= n; i++)
        printf(i == n ? "%d" : "%d ", tree[i]);
    return 0;
}
