#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
string str1, str2, str3;
int main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str1 >> str2 >> str3;
        string res = "";
        int p1 = 0, p2 = 0, p3 = 0;
        while(p1 < 2 * n && p2 < 2 * n && p3 < 2 * n)
        {
            if(str1[p1] == str2[p2])        res += str1[p1], p1++, p2++;
            else if(str1[p1] == str3[p3])   res += str1[p1], p1++, p3++;
            else                            res += str2[p2], p2++, p3++;
        }
        if(p1 >= 2 * n)
            res += (p2 > p3 ? str2.substr(p2, 2 * n - p2) : str3.substr(p3, 2 * n - p3));
        else if(p2 >= 2 * n)
            res += (p1 > p3 ? str1.substr(p1, 2 * n - p1) : str3.substr(p3, 2 * n - p3));
        else
            res += (p1 > p2 ? str1.substr(p1, 2 * n - p1) : str2.substr(p2, 2 * n - p2));
        cout << res << '\n';
    }
    return 0;
}
