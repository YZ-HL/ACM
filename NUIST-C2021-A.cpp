#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, k;
int main(void)
{
    scanf("%d %d", &n, &k);
    if(k == 1)
        printf("champion\n");
    else if(k <= (int)(n * 0.10))
        printf("au\n");
    else if(k - (int)(n * 0.10) <= (int)(n * 0.15))
        printf("ag\n");
    else if(k - (int)(n * 0.10) - (int)(n * 0.15) <= (int)(n * 0.25))
        printf("cu\n");
    else
        printf("fe\n");
    return 0;
}