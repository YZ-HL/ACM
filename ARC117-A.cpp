#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int A, B;
int a[maxn], b[maxn], suma[maxn], sumb[maxn];
int main(void)
{
    scanf("%d %d", &A, &B);
    if(A > B)
    {
        for(int i = 1; i <= A; i++)
            a[i] = i;
        for(int i = 1; i <= B - 1; i++)
            b[i] = -a[i];
        for(int i = B; i <= A; i++)
            b[B] += a[i] * (-1);
    }
    else
    {
        for(int i = 1; i <= B; i++)
            b[i] = -i;
        for(int i = 1; i <= A - 1; i++)
            a[i] = -b[i];
        for(int i = A; i <= B; i++)
            a[A] += b[i] * (-1);
    }
    for(int i = 1; i <= A; i++)
        printf("%d ", a[i]);
    for(int i = 1; i <= B; i++)
        printf("%d ", b[i]);
    return 0;
}
