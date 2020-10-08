#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int n, k, se[55][maxn];
double ans[55][55];
unordered_set<int> s1[55];
double calc(int x, int y){
	int nc = 0, nt = s1[x].size()+s1[y].size();
	for(unordered_set<int>::iterator iter = s1[x].begin(); iter != s1[x].end(); iter++)
		if(s1[y].count(*iter))    nc++;
	//printf("%d %d\n", nc, nt);
	return ans[x][y] = ans[y][x] = 100.0*nc/(nt-nc);
}
int main(void)
{
	for(int i = 1; i <= 50; i++)
		for(int j = 1; j <= 50; j++)
			ans[i][j] = -1.00;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
    	int m;
    	scanf("%d", &m);
    	for(int j = 1; j <= m; j++)
    	{
    		scanf("%d", &se[i][j]);
    		if(!s1[i].count(se[i][j]))
    			s1[i].insert(se[i][j]);
    	}
    	se[i][0] = m;
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; i++)
    {
    	int q1, q2;
    	scanf("%d %d", &q1, &q2);
    	printf("%.2lf%\n", ans[q1][q2] < 0 ? calc(q1, q2) : ans[q1][q2]);
    }
    return 0;
}
