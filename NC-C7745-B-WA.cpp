#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int t;
int l1, l2, l3, a1, a2, a3;
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
    	scanf("%d %d %d %d %d %d", &l1, &l2, &l3, &a1, &a2, &a3);
    	int asum = (~a1 ? a1 : 0) + (~a2 ? a2 : 0) + (~a3 ? a3 : 0);
    	int anum = (~a1 ? 1 : 0) + (~a2 ? 1 : 0) + (~a3 ? 1 : 0);
    	if(!anum)
    	{
    		if(l1 > l2)	swap(l1, l2);
    		if(l1 > l3)	swap(l1, l3);
    		if(l2 > l3)	swap(l2, l3);
    		printf("%d\n", l1 + l2 > l3 ? 1 : 0);
    	}
    	else if(asum > 180)
    		printf("0\n");
    	else if(anum == 3 && asum == 180)
    		printf("syksykCCC\n");
    	else if(anum == 3 && asum != 180)
    		printf("0\n");
    	else if(anum == 2 && asum < 180)
    		printf("syksykCCC\n");
    	else if(anum == 1 && asum < 180)
    	{
    		int nowa = asum, ll1 = -1, ll2 = -1;
    		if(l1 != -1)	l = l1;
    		if(l2 != -1)	l = l2;
    		if(l3 != -1)	l = l3;	
    	}
    	else if()
    }
    return 0;
}
