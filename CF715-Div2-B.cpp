#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int t, n;
string str;
int main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str;
        int cntT = 0, cntTM = 0, cntTMT = 0;
        int len = str.length();
        for(int i = 0; i < len; i++)
        {
            if(str[i] == 'T')
            {
                if(cntTM)    cntTM--, cntTMT++;
                else         cntT++;
            }
            else
            {
                if((!cntT) && cntTMT)
                {
                    cntTMT--;
                    cntTM++; cntTM++;
                }
                else if(cntT)
                {
                    cntT--;
                    cntTM++;
                }
                else    break;
            }
        }
        if(cntTMT * 3 == len)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
