#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, n1, n2, n3, c[maxn], sum[maxn];
void print(int n1, int n2, int n3){
    printf("Outgoing #: %d\n", n1);
    printf("Introverted #: %d\n", n2);
    printf("Diff = %d\n", n3); 
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    sort(c+1, c+n+1);
    for(int i = 1; i <= n; i++)    
        sum[i] = sum[i-1] + c[i];
    if(n & 1)
    {
        int div = n / 2;
        int diff1 = abs((sum[n] - sum[div]) - sum[div]);
        int diff2 = abs((sum[n] - sum[div + 1]) - sum[div + 1]);
        if(diff1 > diff2)
            print(n - div, div, diff1);
        else
            print(n - div - 1, div + 1, diff2);
    }
    else    print(n / 2, n / 2, abs((sum[n] - sum[n/2]) - sum[n/2]));
    
    return 0;
}
