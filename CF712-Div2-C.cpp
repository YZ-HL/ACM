#include <bits/stdc++.h>
#define maxn 400005
using namespace std;
int t, n, ans[maxn];
string str;
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        cin >> str;

        int cnt1 = 0, cnt0 = 0;
        for(int i = 0; i < n; i++)
            str[i] == '1' ? cnt1++ : cnt0++;
        
        if(cnt1 % 2 == 1 || cnt0 % 2 == 1 || str[0] != '1' || str[n - 1] != '1')
        {
            printf("NO\n");
            continue;
        }

        ans[0] = 1; ans[n - 1] = 0;
        int flag1 = 0, flag2 = 1;
        for(int i = 1; i < n - 1; i++)
        {
            if(str[i] == '1')  {flag1 ^= 1; ans[i] = flag1;}
            else               {flag2 ^= 1; ans[i] = flag2;}
        }
        printf("YES\n");
        for(int i = 0; i <= n - 1; i++)
            putchar(ans[i] == 1 ? '(' : ')');
        putchar('\n');
        for(int i = 0; i <= n - 1; i++)
            putchar((ans[i] == 1) ^ (str[i] == '0') ? '(' : ')');
        putchar('\n');
    }
    return 0;
}
