#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int check(int val, int aven){
    int cnt = 0, fail = 0;
    int now = a[1];
    for(int i = 2; i <= n; i++)
    {
        //printf("%d %d\n", i, now);
        if(now == val)
        {
            now = a[i];
        }
        else if(now < val)
        {
            now += a[i];
            cnt++;
        }
        else
        {
            fail = 1;
            break;
        }
    }
    //printf("%d %d %d\n", cnt, val, aven);
    return cnt == aven && !fail;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int sum = 0, flag = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum += a[i];
        for(int i = n; i >= 1 && !flag; i--)
        {
            if(sum % i)    continue;
            flag = check(sum / i, n - i) ? (n - i == 0 ? -1 : n - i) : 0;
        }
        printf("%d\n", flag == -1 ? 0 : flag);
    }
    return 0;
}
