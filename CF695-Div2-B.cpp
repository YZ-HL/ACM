#include <bits/stdc++.h>
#define maxn 1000005
#define int long long
using namespace std;
int t, n, a[maxn];
int check1(int pos){
    if(pos >= 3 && pos <= n - 2)
        if(a[pos] > a[pos-1] && a[pos] > a[pos+1] && a[pos+1] < a[pos+2] && a[pos-1] < a[pos-2])
            return 1;
    return 0;
}
int check2(int pos){
    if(pos >= 3 && pos <= n - 2)
        if(a[pos] < a[pos-1] && a[pos] < a[pos+1] && a[pos+1] > a[pos+2] && a[pos-1] > a[pos-2])
            return 1;
    return 0;
}
int check3(int pos){
    //if(pos >= 2 && pos <= n - 2)
        if(a[pos] > a[pos-1] && a[pos] > a[pos+1] && a[pos+1] < a[pos+2])
            //if(pos+2 == n || a[pos+2] >= a[pos+3])
                //if(pos-1 == 1 || a[pos-1] >= a[pos-2])
                    return 1;
    return 0;
}
int check4(int pos){
    //if(pos >= 2 && pos <= n - 2)
        if(a[pos] < a[pos-1] && a[pos] < a[pos+1] && a[pos+1] > a[pos+2])
            //if(pos+2 == n || a[pos+2] >= a[pos+3])
                //if(pos-1 == 1 || a[pos-1] <= a[pos-2])
                    return 1;
    return 0;
}
signed main(void)
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        
        int flag = 0, flag2 = 0, num = 0;
        
        for(int i = 1; i <= n - 1; i++)
            flag2 |= (check3(i) | check4(i));

        for(int i = 2; i <= n - 1; i++)
        {
            flag |= (check1(i) | check2(i));
            if(a[i] > a[i-1] && a[i] > a[i+1])  num++;
            if(a[i] < a[i-1] && a[i] < a[i+1])  num++;
        }
        //printf("%lld %lld %lld\n", flag, flag2, num);

        if(flag)
            printf("%lld\n", num-3);
        else if(flag2)
            printf("%lld\n", num-2);
        else if(num)
            printf("%lld\n", num-1);
        else
            printf("%lld\n", num);
    }
    return 0;
}
