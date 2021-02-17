#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, t, las[maxn], proi[maxn], can[maxn];
struct sta{
    int ts;
    int id;
} order[maxn];
bool cmp(const sta &A, const sta &B){
    return A.ts < B.ts;
}
int main(void)
{
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &order[i].ts, &order[i].id);
    sort(order + 1, order + m + 1, cmp);
    for(int i = 1; i <= m; i++)
    {
        if(las[order[i].id] && las[order[i].id] != order[i].ts)
            proi[order[i].id] = max(0, proi[order[i].id] - (order[i].ts - las[order[i].id] - 1));
        
        if(proi[order[i].id] <= 3)      can[order[i].id] = 0;        
        proi[order[i].id] += 2;        
        if(proi[order[i].id] > 5)       can[order[i].id] = 1;
        las[order[i].id] = order[i].ts;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(las[i] != t)  
            proi[i] = max(0, proi[i] - (t - las[i]));
        if(proi[i] > 5)         can[i] = 1;
        else if(proi[i] <= 3)   can[i] = 0;
        ans += can[i];
    }
    printf("%d\n", ans);
    return 0;
}
