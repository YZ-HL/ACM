#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, cnt, pri[maxn], num[maxn];
bool isp[maxn]; 
void euler(int limit){
    memset(isp, true, sizeof(isp));
    isp[1] = false;
    for(int i = 2; i <= limit; i++)
    {
        if(isp[i])    pri[++cnt] = i;
        for(int j = 1; j <= cnt && pri[j] * i <= limit; j++)
        {
            isp[pri[j] * i] = false;
            if(i % pri[j] == 0)    break;
        }
    }
}
int main(void)
{
    euler(100000);
    pri[0] = -1;
    for(int i = 1; i <= cnt; i++)
    {
        if(pri[i] - pri[i-1] == 2)
            num[pri[i]]++;
    }
    for(int i = 1; i <= 100000; i++)
        num[i] = num[i-1] + num[i];
    while(scanf("%d", &n) && n > 0)
    {
        printf("%d\n", num[n]);
    }
    return 0;
}
