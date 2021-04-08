#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n;
string str;
signed main(void)
{
    cin >> n;
    cin >> str;
    if(n == 1 && str[0] == '1')
    {
        printf("%lld\n", (long long)2e10);
        return 0;
    }
    int len = str.length();
    int ooz = 0, cnt1 = 0, ishead = 1, fail = 0, haspre = 0, hassuf = 0;
    for(int i = 0; i <= len - 1 && !fail; i++)
    {
        if(str[i] == '0')
        {
            if(ishead)
            {
                ishead = 0;
                if(cnt1 != 2)
                    haspre = 1;
                else
                    ooz++;
                cnt1 = 0;
            }
            else
            {
                if(cnt1 != 2)   fail = 1;
                else
                {
                    cnt1 = 0;
                    ooz++;
                }
            }
        }
        else
        {
            cnt1++;
            if(cnt1 > 2)    fail = 1;
        }        
    }
    if(fail)
    {
        printf("0\n");
        return 0;
    }
    if(cnt1 != 0)   hassuf = 1;
    int add = 0;
    if(haspre && hassuf)    add = 1;
    else if(!haspre && !hassuf)    add = -1;
    printf("%lld\n", (long long)1e10 - ooz - add);
    //printf("%d %d %d\n", haspre, hassuf, ooz);
    return 0;
}
