#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
struct Node{
    int pre;
    int nxt;
}N[30][maxn];
int las[30];
string str;
signed main(void)
{
    cin >> str;
    int len = str.length();
    memset(N, -1, sizeof(N));
    memset(las, -1, sizeof(las));
    for(int i = 0; i <= 25; i++)
        for(int j = 0; j <= len - 1; j++)
            N[i][j].pre = -1, N[i][j].nxt = len;
    for(int i = 0; i <= len - 1; i++)
    {
        if(las[str[i] - 'a'] == -1)
            las[str[i] - 'a'] = i;
        else
            N[str[i] - 'a'][i].pre = las[str[i] - 'a'], las[str[i] - 'a'] = i;
    }
    memset(las, -1, sizeof(las));
    for(int i = len - 1; i >= 0; i--)
    {
        if(las[str[i] - 'a'] == -1)
            las[str[i] - 'a'] = i;
        else
            N[str[i] - 'a'][i].nxt = las[str[i] - 'a'], las[str[i] - 'a'] = i;
    }
    int ans = 0;        
    for(int i = 0; i <= len - 1; i++)
    {
        //printf("%lld %lld %c %lld\n", N[str[i] - 'a'][i].pre, N[str[i] - 'a'][i].nxt, str[i], i);
        //if(N[str[i] - 'a'][i].pre == -1 || N[str[i] - 'a'][i].nxt == -1)    continue;
        ans += (N[str[i] - 'a'][i].nxt - i) * (i - N[str[i] - 'a'][i].pre); 
    }
    printf("%lld\n", ans);
    return 0;
}
