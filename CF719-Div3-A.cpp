#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int t, n;
bool vis[maxn];
string str;
int main(void)
{
    cin >> t;
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n;
        cin >> str;
        int len = str.length(), flag = 0;
        for(int i = 0; i < len; i++)
        {
            if(vis[str[i]])
            {
                flag = 1;
                break;
            }
            if(i && str[i - 1] != str[i])
            {
                vis[str[i - 1]] = 1;
            }
        }
        printf(flag ? "NO\n" : "YES\n");
    }
    return 0;
}
