#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;
int n, a[maxn], ans[maxn], uset[maxn];
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)         scanf("%d", &a[i]);
    for(int i = 1; i <= maxn; i++)      uset[i] = i;
    for(int i = 1; i <= n; i++)
    {
        if(find(a[i]) == a[i])
        {
            ans[i] = a[i];
            uset[a[i]] = find(a[i] + 1);
        }
        else
        {
            ans[i] = find(a[i]);
            uset[ans[i]] = find(ans[i] + 1);
        }
    }

    for(int i = 1; i <= n; i++)
        printf(i == n ? "%d\n" : "%d ", ans[i]);
    
    return 0;
}
