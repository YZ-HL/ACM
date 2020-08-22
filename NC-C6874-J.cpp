#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int tmp, sum;
int main(void)
{
    int n, endd = 0;
    scanf("%d", &n);
    string tmp;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        int len = tmp.length();
        int ttmp = tmp[len-1]-'0';
        endd += ttmp;
    }
    printf("%d\n", endd&1 ? 1 : 0);
    return 0;
}
