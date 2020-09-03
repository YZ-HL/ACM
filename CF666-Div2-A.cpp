#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        int num[30];
        memset(num, 0, sizeof(num));

        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            string tmp;
            cin >> tmp;
            int len = tmp.length();
            for(int j = 0; j <= len-1; j++)
                num[tmp[j]-'a'+1]++;
        }
        int flag = 1;
        for(int i = 1; i <= 26 && flag; i++)
            if(num[i] % n)  flag = 0;

        printf(flag ? "YES\n" : "NO\n");
    }
    system("pause");
    return 0;
}
