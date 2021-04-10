#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, now, cnt, flag;
string str;
int main(void)
{
    cin >> str;
    if(str.length() == 1 && str[0] == '1')
    {
        printf("%d\n", 0);
        return 0;
    }
    int len = str.length();
    for(int i = 0; i <= len - 1; i++)
    {
        if(str[i] == '1')    now++;
        else
        {
            if(now)
            {
                if(now == 1)    flag = 1;
                now = 0;
                cnt++;
            }
            if(i < len - 1 && str[i - 1] == '1' && str[i + 1] == '1')
                flag = 1;
        }
    }
    //printf("%d\n", now);
    if(now)
        cnt++;
    if(now == 1)
    {
        flag = 1;
    }
    printf("%d\n", flag ? cnt - 1 : cnt);
    return 0;
}
