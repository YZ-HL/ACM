#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int t, n;
string str;
string or_str(string a, string b){
    int len = a.length();
    string res = "";
    for (int i = 0; i <= len-1; i++)
        a[i] == '0' && b[i] == '0' ? res += '0' : res += '1';
    return res;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        cin >> n;
        cin >> str;
        int pos = 0;
        string ans = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        for (int i = 1; i <= n; i++)
        {
            string tmp = str.substr(pos, n);
            //cout << tmp << endl;
            ans = or_str(tmp, ans);
            pos++;
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
