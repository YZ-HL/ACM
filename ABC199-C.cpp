#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, q, t;
string str;
int main(void)
{
    cin >> n;
    cin >> str;
    cin >> q;
    int flag = 0;
    for(int i = 1; i <= q; i++)
    {
        int ai, bi;
        cin >> t >> ai >> bi;
        if(t == 1)
        {
            if(!flag)
                swap(str[ai - 1], str[bi - 1]);
            else
                swap(str[(ai + n - 1) % (2 * n)], str[(bi + n - 1) % (2 * n)]);
        }
        else
            flag ^= 1;
    }
    if(flag)
        str = str.substr(n, n) + str.substr(0, n);
    cout << str << '\n';
    return 0;
}
