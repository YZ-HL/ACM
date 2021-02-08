//疑似NOJ数据有括号不匹配问题？前一分代码会TLE
//首次提交时只考虑了xx|xx情况，没有考虑xxx|xxx|xx|x情况
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
    cout << dfs(0).maxx << endl;
    return 0;
}
