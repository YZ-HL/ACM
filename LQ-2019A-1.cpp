#include <bits/stdc++.h>
using namespace std;
bool check(int num){
    while(num)
    {
        int tmp = num % 10;
        num /= 10;
        if(tmp == 2 || tmp == 0 || tmp == 1 || tmp == 9)
            return true;
    }
    return false;
}
int main(void)
{
    long long sum = 0;
    for(int i = 1; i <= 2019; i++)
        if(check(i))    sum += 1LL * i * i;
    printf("%lld\n", sum);
    return 0;
}