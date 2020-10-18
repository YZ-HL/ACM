#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int a[maxn], ans[maxn];
int sum, flag = 1;
void dfs(int len, int num){
	if(!flag)	return;
	if(len * 2 == sum - 1)
	{
		int num = 0, pos = -1;
		for(int i = 0; i <= 9; i++)
			if(a[i] == 1)
			{
				num++;
				pos = i;
			}
		if(num == 1)
		{
			for(int i = 0; i <= len - 1; i++)
				printf("%d", ans[i]);
			printf("%d", pos);
			for(int i = len - 1; i >= 0; i--)
				printf("%d", ans[i]);
		}
		flag = 0;
		return;
	}
	if(len * 2 == sum)
	{
		for(int i = 0; i <= len - 1; i++)
			printf("%d", ans[i]);
		for(int i = len - 1; i >= 0; i--)
			printf("%d", ans[i]);
		flag = 0;
		return;
	}
	for(int i = 0; i <= 9; i++)
	{
		if(!len && !i)	continue;
		if(a[i] > 1)
		{
			a[i] -= 2; 
			ans[len] = i;
			dfs(len+1, num+2);
			break;
		}
	}
}
int main(void)
{
    for(int i = 0; i <= 9; i++)
    	scanf("%d", &a[i]), sum += a[i];
    dfs(0, 0);
    if(flag)
    	printf("%d", -1);
    return 0;
}
