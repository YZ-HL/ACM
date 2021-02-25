#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, l, lp, cnt[maxn][30];
string str;
int main(void)
{
    cin >> t;
    while(t--)
    {
        //memset(cnt, 0, sizeof(cnt));
        string ans = "";
        cin >> n >> l;
        cin >> str;
        if(n > 2 * l)    lp = __gcd(n, l);
        else             lp = n - l;
        
        for(int i = 0; i <= lp - 1; i++)
            for(int j = 1; j <= 26; j++)
                cnt[i][j] = 0;
        
        for(int i = 0; i <= n - 1; i++)
        {
            cnt[i % lp][str[i] - 'a' + 1]++;
        }
        for(int i = 0; i <= lp - 1; i++)
        {
            int maxx = 0, pos = 0;
            for(int j = 1; j <= 26; j++)
                if(maxx < cnt[i][j])
                    maxx = cnt[i][j], pos = j;
            ans += (char)(pos + 'a' - 1);
        }
        cout << ans;
        for(int i = lp; i <= n - 1; i++)
            cout << ans[i % lp];
        cout << '\n';
    }
    return 0;
}