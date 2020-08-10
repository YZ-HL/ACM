#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 1005
using namespace std;
int t, pr[maxn][maxn];
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
void inits(){
    //memset(pr, -1, sizeof(pr));
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            pr[i][j] = max(pr[i-1][j], pr[i][j-1]) + (((i == 1 && j == 1) || gcd(max(i, j), min(i, j)) == 1) ? 1 : 0);    
/*
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
            printf("%d ", pr[i][j]);
        putchar('\n');
    }
*/
}
int main(void)
{
    inits();
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        //if(n < m)   swap(n, m);
        printf("%d\n", pr[n][m]);
    }
    //system("pause");
    return 0;
}