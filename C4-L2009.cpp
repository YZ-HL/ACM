#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int n, k;
struct P{
	int num;
	int num_l;
	int income;
} info[maxn];
bool cmp(const P &A, const P &B){
	if(A.income != B.income)
		return A.income > B.income;
	if(A.num_l != B.num_l)
		return A.num_l > B.num_l;
	return A.num < B.num;
}
int main(void)
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		info[i].num = i;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		{
			int tmp_n, tmp_i;
			scanf("%d %d", &tmp_n, &tmp_i);
			info[tmp_n].income += tmp_i;
			info[tmp_n].num_l++;
			info[i].income -= tmp_i;
		}
	}
	sort(info+1, info+n+1, cmp);
	for(int i = 1; i <= n; i++)
	{
		printf("%d %.2lf", info[i].num, 1.0*info[i].income/100);
		if(i != n)	putchar('\n');
	}
    return 0;
}
