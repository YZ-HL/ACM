#include <bits/stdc++.h>
#define maxn 300005
using namespace std;
int t, k, m, sum, res, a[maxn], id[maxn], tmp[maxn];
int Merge(int lf, int rt, int tl, int tr){
    int mid = (lf + rt) / 2;
    int i = lf, j = mid + 1, k = lf; 
    
    if(a[id[i]] < a[id[j]])
        while(i <= tl && a[id[i]] + m < a[id[j]])    i++;
    else
        while(j <= tr && a[id[j]] + m < a[id[i]])    j++;

    while(i <= tl && j <= tr)
        tmp[k++] = a[id[i]] < a[id[j]] ? id[i++] : id[j++];
    while(i <= tl)
        tmp[k++] = id[i++];
    while(j <= tr)
        tmp[k++] = id[j++];
    for(int i = lf; i <= k - 1; i++)    id[i] = tmp[i];
    return k - lf;
}
int MergeSort(int lf, int rt){
    if(lf == rt)    return 1;
    int mid = (lf + rt) / 2;
    int tl = MergeSort(lf, mid) + lf - 1;
    int tr = MergeSort(mid + 1, rt) + mid;
    return Merge(lf, rt, tl, tr);
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &k, &m);
        sum = 1 << k;
        for(int i = 1; i <= sum; i++)
            scanf("%d", &a[i]), id[i] = i;
        res = MergeSort(1, sum);
        int flag = 0;   
        for(int i = 1; i <= res; i++)
            if(id[i] == 1)
            {
                flag = 1;
                break;
            }
        printf(flag ? "Kotori\n" : "Yoshino\n");
    }
    return 0;
}
