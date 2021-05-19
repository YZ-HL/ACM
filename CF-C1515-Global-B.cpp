#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
set<int> s1;
int main(void)
{
    for(int i = 1; i * i <= 1e9; i++)    s1.insert(i * i);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n == 1)
        {
            printf("NO\n");
            continue;
        }
        int r = n, bas = 1, flag = 0;
        while(r % 2 == 0)
        {
            bas *= r;
            r /= 2;
            if(s1.count(r))
            {
                flag = 1;
                break;
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}
