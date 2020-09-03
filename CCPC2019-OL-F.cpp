#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, m, a[maxn], od[maxn], used[maxn];
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d", &od[i]);
    
    for(int i = m; i >= 1; i--)
        !used[od[i]] ? printf("%d ", od[i]), used[od[i]] = 1 : 0;
    
    for(int i = 1; i <= n; i++)
        !used[a[i]] ? printf("%d ", a[i]), used[a[i]] = 1 : 0;
    
    system("pause");
    return 0;
}
