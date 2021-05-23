#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t;
string str, ans;
int main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> str;
        int len = str.length();
        int lf = 0, rt = len - 1, flag = 0;
        while(lf < rt && !flag)
        {
            if(str[rt] != 'a' || str[lf] != str[rt - 1])
                ans = str.substr(0, lf) + 'a' + str.substr(lf, len - lf + 1), flag = 1;
            else if(str[lf] != str[rt] || str[rt - 1] != 'a')
                ans = str.substr(0, lf + 1) + 'a' + str.substr(lf + 1, len - lf), flag = 1;
            lf++; rt--;
        }
        if(lf == rt && !flag)    
        {
            if(str[lf] == 'a')
                flag = 0;
            else
                ans = str.substr(0, lf) + 'a' + str.substr(lf, len - lf + 1), flag = 1;
        }
        if(flag)
        {
            cout << "YES\n";
            cout << ans << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
