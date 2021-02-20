#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, k, num[maxn], r[maxn], used[maxn];
int check(){
    int res = 0;
    for(int i = 1; i <= n - 1; i++)
        if(__gcd(num[i], num[i + 1]) > 1)   res++;
    return res;
}
int main(void)
{
    scanf("%d %d", &n, &k);
    int flag = 0;
    if(n < 6)
    {
        for(int i = 1; i <= n; i++)    num[i] = i;
        do{
            if(check() == k)
            {
                flag = 1;
                break;
            }
        }while(next_permutation(num + 1, num + n + 1));
    }
    else
    {
        flag = 1;
        for(int i = 1; i <= n / 2 + 1 && i <= k + 1; i++)
        {
            num[i] = 2 * i;
            if(i == n / 2 + 1)    swap(num[i - 1], num[3]), num[i] = 3;
            used[num[i]] = 1;
        }
        num[k + 2] = 1; used[1] = 1;
        for(int i = 1; i <= n; i++)    
            if(!used[i])    r[++r[0]] = i;
        for(int i = k + 3; i <= n; i++)
        {
            num[i] = r[i - k - 2];
        }
    }
    if(!flag)
        printf("-1\n");
    else
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%d\n" : "%d ", num[i]);
    //printf("%d %d\n", check(), k);
    return 0;
}