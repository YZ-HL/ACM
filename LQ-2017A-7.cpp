#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int len, ans;
string str;
struct RE{
    int pos;
    int maxx;
};
RE dfs(int s){
    int now = 0, maxx = 0, endpos = -1;
    for(int i = s + 1; i <= len - 1; i++)
    {
        if(str[i] == '(')
        {
            RE tmp = dfs(i);
            i = tmp.pos;
            now += tmp.maxx;
        }
        else if(str[i] == '|')
        {
            maxx = max(maxx, now);
            now = 0;
        }
        else if(str[i] == 'x')
        {
            now++;
        }
        else if(str[i] == ')')
        {
            maxx = max(maxx, now);
            endpos = i;
            break;
        }
    }
    return (RE){endpos, max(maxx, now)};
}
int main(void)
{
    cin >> str;
    str = '(' + str + ')';
    len = str.length();
    for(int i = 0; i <= len - 1; i++)
    {
        if(str[i] == '(')
        {
            RE tmp = dfs(i);
            i = tmp.pos;
            ans += tmp.maxx;
        }
        else if(str[i] == 'x')
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
