#include <bits/stdc++.h>

using namespace std;

int n, k;
string ans;

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        ans += 'a' + i;
        for(int j = i + 1; j < k; j++)
        {
            ans += 'a' + i;
            ans += 'a' + j;
        }
    }
    int len = ans.length();
    while(ans.length() < n)
        ans += ans.substr(0, len);
    cout << ans.substr(0, n);
    return 0;
}