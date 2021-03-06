#include <bits/stdc++.h>
const int maxn =  1e5 + 5;
using namespace std;
struct res{
    int id;
    string s;
}r[maxn];
int n, m, ans, acs[maxn], was[maxn], flag[maxn];
int main(void)
{
    cin >> m >> n;
    ans = n;
    for(int i = 1; i <= m; i++)
    {
        cin >> r[i].id >> r[i].s;
        if(r[i].s == "AC")
            acs[r[i].id]++;
        else
            was[r[i].id]++;
        if(!flag[r[i].id] && 1.0 * acs[r[i].id] / (acs[r[i].id] + was[r[i].id]) < 0.5)
        {
            flag[r[i].id] = 1;
            ans--;
        }
    }
    for(int i = 1; i <= n; i++)
        if(flag[i] == 0)
            printf("%d ", i);
    if(ans == 0)
        printf("-1\n");
    return 0;
}