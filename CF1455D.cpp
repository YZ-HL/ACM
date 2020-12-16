#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, x, a[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int ans = 0;
        scanf("%d %d", &n, &x);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
        {
            if(is_sorted(a+1, a+n+1))
                break;
            if(a[i] > x)    
            {
                swap(x, a[i]);
                ans++;
            }
        }
        printf("%d\n", is_sorted(a+1, a+n+1) ? ans : -1);
    }
    return 0;
}
