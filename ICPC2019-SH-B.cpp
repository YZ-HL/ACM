#include <bits/stdc++.h>
#define maxn 10005
#define int long long
using namespace std;
char str[15], s[maxn][15];
unordered_map<string, int> mp;
signed main(void)
{
    int t, cases = 0;
    scanf("%lld", &t);
    while(t--)
    {
        memset(s, 0, sizeof(s));
        mp.clear();
        int n, maxx = 0;
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)    
        {
            scanf("%s", str);
            int len = strlen(str);
            for(int j = len; j > 0; j--)
            {
                s[i][j-1] = str[j-1];
                str[j] = '\0'; 
                mp[str]++;
                //printf("de: %d ", mp[str]);
                //cout << str << endl;
            }
        }
        for(int i = 1; i <= n; i++)    maxx = max(mp[s[i]], maxx);
        //printf("%d\n", maxx);
        printf("Case #%lld: ", ++cases);
        printf(maxx > 1 ? "No\n" : "Yes\n");
    }
    return 0;
}
