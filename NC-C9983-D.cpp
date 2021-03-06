#include <bits/stdc++.h>
using namespace std;
int n;
int calc(int x){
    int sum = 0;
    while(x)
        sum += x % 10, x /= 10;
    return sum;
}
int main(void)
{
    scanf("%d", &n);
    int r = calc(n);
    for(int i = n + 1; ; i++)
        if(calc(i) == r)
        {
            printf("%d\n", i);
            break;
        }
    return 0;
}