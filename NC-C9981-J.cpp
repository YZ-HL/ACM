#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
int num, pri[maxn], r[maxn];
bool isp[maxn];
void euler(int lim){
    memset(isp, true, sizeof(isp));
    isp[0] = isp[1] = false;
    for(int i = 2; i <= lim; i++)
    {
        if(isp[i])    pri[++num] = i;
        for(int j = 1; j <= num && i * pri[j] <= lim; j++)
        {
            isp[i * pri[j]] = false;
            if(i % pri[j] == 0)
            {
                break;
            }
        }
    }
}
int calc(int bas, int p){
    if(p == 0)  return 1;
    int res = 1;
    for(int i = 1; i <= p; i++)
        res *= bas;
    return res;
}
int main(void)
{

    int lim = 25;
    euler(lim);
    
    for(int i = 1; i <= num; i++)
        for(int j = 0; calc(pri[i], j) <= lim; j++)
            r[calc(pri[i], j)] = 1;
    
    int lcm = -1;
    for(int i = 1; i <= lim; i++)
        if(!r[i])
        {
            if(lcm == -1)    lcm = i;
            else           
            {
                lcm = lcm * i / __gcd(lcm, i);
            }
        }            
    printf("%d\n", lcm);  
    return 0;
}
/* < 5   empty
 * 6~10  6
 * 11    30
 * 12~13 60
 * 14~17 420
 * 18    1260
 */ 