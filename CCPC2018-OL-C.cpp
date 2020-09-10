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
        int p;
        scanf("%d", &p);
        for(int i = 1; i <= p; i++)
            for(int j = 1; j <= p; j++)
                printf("%d", ((((i-1)%p)+(((j-1)%p)))%p)), putchar(j == p ? '\n' : ' ');
        for(int i = 1; i <= p; i++)
            for(int j = 1; j <= p; j++)
                printf("%d", ((((i-1)%p)*(((j-1)%p)))%p)), putchar(j == p ? '\n' : ' ');
    }
    system("pause");
    return 0;
}
