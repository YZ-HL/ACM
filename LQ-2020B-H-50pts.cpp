#include <bits/stdc++.h>
#define maxn 205
using namespace std;
string str;
int vis[maxn], fir[maxn];
int main(void)
{
    cin >> str;
    int len = str.length(), rep = 0, ans = 0;
    for(int i = 0; i <= len - 1; i++)
    {
        rep = 0;
        memset(vis, 0, sizeof(vis));
        memset(fir, 0, sizeof(fir));
        for(int j = i; j <= len - 1; j++)
        {
            if(vis[str[j]] == 0)    
                vis[str[j]] = 1;
            else if(vis[str[j]] == 1)
            {
                if(!fir[str[j]])    rep += 2, fir[str[j]] = 1;
                else                rep++;
            }
            ans += (j - i + 1) - rep;
        }
    }
    printf("%d\n", ans);
    return 0;
}
