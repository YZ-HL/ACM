#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
#define eps 1e-8
using namespace std;
int n, d;
struct Sell{
	double avg;
	double num;
	double sum;
} S[maxn];
bool cmp(const Sell &A, const Sell &B){
	return fabs(A.avg-B.avg) > eps ? A.avg > B.avg : A.num > B.num;
}
int main(void)
{
	scanf("%d %d", &n, &d);
	for(int i = 1; i <= n; i++)
		scanf("%lf", &S[i].num);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf", &S[i].sum);
		S[i].avg = S[i].sum/S[i].num;
	}
	sort(S+1, S+n+1, cmp);
	int now = 1;
	double ans = 0;
	while(d && now <= n)
	{
		if((int)S[now].num <= d)
		{
			d -= S[now].num;
			ans += S[now].sum;
			now++;
			continue;
		}
		ans += S[now].avg*d;
		d = 0;
	}
	printf("%.2lf", ans);
    return 0;
}
