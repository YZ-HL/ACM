#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, p[maxn], h[maxn];
int bins(int lf, int rt, int val){
	int pos = -1;
	while(lf <= rt)
	{
		//printf("%d %d\n", lf, rt);
		int mid = (lf + rt) / 2;
		val < h[mid] ? pos = mid, rt = mid - 1 : lf = mid + 1;
	}
	return pos;
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &p[i]);
    memset(h, 0x3f, sizeof(h));
    h[0] = 0;
    for(int i = 1; i <= n; i++)
    {
    	if(!h[0] || h[h[0]] < p[i])
    	{
    		h[++h[0]] = p[i];
    	}
    	else
    	{
    		/*
    		for(int i = 1; i <= h[0]; i++)
    			printf("%d ", h[i]);
    		putchar('\n');
    		*/
    		int pos = bins(1, h[0], p[i]);
    		h[pos] = p[i];
    	}
    }
	printf("%d", h[0]);
    return 0;
}
