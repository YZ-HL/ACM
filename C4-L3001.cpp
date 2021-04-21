#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, m, a[maxn], b[maxn], dp[maxn];
void print(int x){
    if(x == b[x])
    {
        printf("%d", x);
        return;
    }
    print(x - b[x]);
    printf(" %d", b[x]);    
}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= a[i]; j--)
        {
            if((dp[j - a[i]] || j - a[i] == 0) && dp[j] <= dp[j - a[i]] + 1)
            {
                dp[j] = dp[j - a[i]] + 1;
                b[j]  = a[i];
            }
        }
    if(b[m] == 0)    printf("No Solution\n");
    else             print(m);
    return 0;
}
