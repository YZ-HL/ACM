#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, t, num[maxn];
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i-1]);
    scanf("%d", &t);
    int lf = 0, rt = n-1;
    while(lf <= rt)
    {
        int mid = (lf+rt)/2;
        t > num[mid] ? lf = mid + 1 : rt = mid - 1;
    }
    printf("%d\n", lf);
    system("pause");
    return 0;
}