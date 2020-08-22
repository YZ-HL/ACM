#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    double res = pow(n, 1.0/3)*3;
    printf("%.3f\n", res);
    return 0;
}
