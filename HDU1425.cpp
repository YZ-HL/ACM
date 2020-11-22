#include <bits/stdc++.h>
#define maxn 1000005 
using namespace std;
int n, m, a[maxn]; 
void qsort(int lf, int rt){
    if(lf >= rt)    return; 
    int mid = a[(lf + rt) / 2];
    int i = lf, j = rt; 
    while(i <= j)
    {
        while(a[i] < mid)    i++;
        while(a[j] > mid)    j--;
        if(i <= j)
        {
            swap(a[i], a[j]); 
            i++;
            j--; 
        }
    }
    qsort(lf, j);
    qsort(i, rt);
} 
int main(void)
{
    while(~scanf("%d %d", &n, &m))
    { 
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        qsort(1, n);
        for(int i = n; i >= n-m+1; i--)
            printf(i == n-m+1 ? "%d\n" : "%d ", a[i]);
    } 
    return 0; 
} 