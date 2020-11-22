#include <bits/stdc++.h>
#define maxn 100005 
#define int long long
using namespace std;
int n, m, a[maxn];
double c1[maxn], c2[maxn]; 
double fl(int x){
    double tmp = 1;
    for(int i = 1; i <= x; i++)
        tmp *= i;
    return tmp; 
} 
signed main(void)
{
     while(~scanf("%lld %lld", &n, &m))
     { 
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        
         for(int i = 1; i <= n; i++)    scanf("%lld", &a[i]); 
         
        for(int i = 0; i <= a[1]; i++)
            c1[i] = 1.0 / fl(i), c2[i] = 0;
            
        for(int k = 2; k <= n; k++)
        {
            for(int i = 0; i <= m; i++)
                for(int j = 0; j <= a[k] && i + j <= m; j++)
                    c2[i+j] += c1[i] / fl(j); 
                
            for(int i = 0; i <= m; i++)
                c1[i] = c2[i], c2[i] = 0;
        }
        printf("%.0lf\n", c1[m] * fl(m));
     }
     return 0; 
} 