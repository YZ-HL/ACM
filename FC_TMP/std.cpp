#include<bits/stdc++.h>
using namespace std;

int a[100005],Max[100005]={0};
int main()
{
    int i,n,DP;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)
    {
        if(i>=a[i])DP=Max[i-a[i]]+1;
        else DP=0;
        Max[i]=max(Max[i-1],DP);
    }
    if(!DP)DP=-1;
    printf("%d\n",DP);
    return 0;
}