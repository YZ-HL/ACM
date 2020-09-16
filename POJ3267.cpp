#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int w, l, dp[maxn];
char str[maxn];
char key[605][maxn];
int main(void)
{
    scanf("%d %d", &w, &l);
    scanf("%s", str+1);
    for(int i = 1; i <= w; i++)
        scanf("%s", key[i]+1);
    for(int i = 1; i <= l; i++)
    {
        dp[i] = i;
        for(int j = 1; j <= w; j++)
        {
            int pos = i, check = strlen(key[j]+1);
            while(pos > 0 && check > 0)
            {
                if(str[pos] == key[j][check])
                    check--;
                pos--;
            }
            if(!check)
                dp[i] = min(dp[i], dp[pos]+(i-pos-(int)strlen(key[j]+1)));
        }
        dp[i] = min(dp[i], dp[i-1]+1);
    }
    printf("%d\n", dp[l]);
    system("pause");
    return 0;
}
