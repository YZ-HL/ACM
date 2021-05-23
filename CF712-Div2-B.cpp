#include <bits/stdc++.h>
#define maxn 600005
using namespace std;
int t, n, c[maxn], sum1[maxn], sum0[maxn];
string str1, str2;
int main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str1 >> str2;
        int len = str1.length();
        for(int i = 1; i <= len; i++)
        {
            c[i] = str1[i - 1] != str2[i - 1] ? 1 : 0;
            sum1[i] = sum1[i - 1] + (str1[i - 1] == '1' ? 1 : 0);   
            sum0[i] = sum0[i - 1] + (str1[i - 1] == '0' ? 1 : 0);   
        }
        int pos = len, fail = 0;
        while(pos > 0 && !fail)
        {
            int rt = pos, lf = -1;
            while(c[pos] == 1 && pos > 0)    lf = pos--;
            if(~lf)
                fail = (sum1[rt] - sum1[lf - 1] != sum0[rt] - sum1[lf - 1]) || (sum0[lf - 1] != sum1[lf - 1]);
            pos--;
        }
        printf(fail ? "NO\n" : "YES\n");
    }
    return 0;
}
