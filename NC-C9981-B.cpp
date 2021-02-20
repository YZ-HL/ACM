#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n, k;
string ans;
int calc(int x){
    return x * x;
}
signed main(void)
{
    scanf("%lld", &n);
    if(n == 0)
    {
        cout << ")" << endl;
        return 0;
    }
    int now = (int)sqrt(n), lf = 0;
    while(now)
    {
        if(n >= calc(now) + lf * now && n - (calc(now) + lf * now) >= lf + now)
        {
            n -= calc(now) + lf * now;
            for(int i = 1; i <= now; i++)
                ans += '(';
            for(int i = 1; i <= now; i++)
                ans += ')';
            lf += now;
        }
        now--;
    }
    if(n && n >= lf)
    {
        for(int i = 1; i <= n - lf; i++)
            ans += '(';
        ans += ')';
    }
    cout << ans << endl;
    //cout << ans.length() << endl;
}
//536870912