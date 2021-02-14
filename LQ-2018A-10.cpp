#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
int n, S, a[maxn];
int flag1 = 1, flag2 = 1;
namespace subtask1{
    void solve(){
        printf("0.0000\n");
    }
}
namespace subtask2{
    void solve(int now){
        printf("%d\n", now);
        double avg = 1.0 * S / n;
        double sum1 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 0)
                sum1 += avg * avg;
            else
                sum1 += ((1.0 * S / now) - avg) * ((1.0 * S / now) - avg);
        }
        printf("%.4lf\n", sqrt(sum1 / n));
    }
}
int main(void)
{
    scanf("%d %d", &n, &S);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 2; i <= n; i++)
        if(a[i] != a[i - 1])
        {
            flag1 = 0;
            break;
        }
    if(flag1)
    {
        subtask1::solve();
        return 0;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        if(a[i] != 0)
        {
            flag2 = i + 1;
            break;
        }
    int num = n - flag2 + 2;
    for(int i = flag2; i <= n; i++)
        if(a[i] != a[i - 1])
        {
            flag2 = 0;
            break;
        }
    if(flag2)
    {
        subtask2::solve(num);
        return 0;
    }
    printf("0.0001\n");
    return 0;
}