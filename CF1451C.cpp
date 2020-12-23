#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int t, n, k, have[30], need[30];
char str1[maxn], str2[maxn];
bool check(){
    memset(have, 0, sizeof(have));
    memset(need, 0, sizeof(need));
    for (int i = 1; i <= n; i++)
        have[str1[i] - 'a']++, need[str2[i] - 'a']++;
    bool flag = true;
    for(int i = 0; i <= 25; i++)
    {
        if(have[i] < need[i] || (have[i] -= need[i]) % k)
        {
            flag = false;
            break;
        }
        have[i + 1] += have[i]; 
    }
    return flag;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        getchar();
        scanf("%s", str1+1);
        scanf("%s", str2+1);
        printf(check() ? "Yes\n" : "No\n");
    }
    return 0;
}
