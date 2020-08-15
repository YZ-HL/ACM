#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, cnt, a[maxn];
string str;
bool cmp(const int &a, const int &b){
    return a > b;
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        memset(a, 0, sizeof(a));

        cin >> str;
        int le = str.length();
        for (int i = 0; i <= le - 1; i++)
        {
            int sl = 0;
            while(str[i] == '1')
            {
                sl++;
                i++;
            }
            if(sl)
            {
                a[cnt] = sl;
                cnt++;
            }
        }
        sort(a, a + cnt, cmp);
        int ans = 0;
        for (int i = 0; i <= cnt; i += 2)
            ans += a[i];
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}