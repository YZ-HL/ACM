#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, m, a[maxn], r[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
    	memset(r, 0, sizeof(r));
    	scanf("%d %d", &n, &m);
    	for(int i = 1; i <= n; i++)
    		scanf("%d", &a[i]), r[a[i] % m]++;
    	int ans = 0;
    	if(r[0])	ans++;
    	for(int i = 1; i <= m / 2; i++)
    	{
    		if(r[i] == 0 && r[m - i] == 0)	continue;
    		int minn = min(r[i], r[m - i]);
    		if(minn + 1 <= r[i])
    		{
    			r[i] -= minn + 1;
    			r[m - i] -= minn;
    			ans++;
    		}
    		else if(minn + 1 <= r[m - i])
    		{
    			r[m - i] -= minn + 1;
    			r[i] -= minn;
    			ans++;
    		}
    		else if(r[i] == r[m - i] && i != m - i)
    		{
    			r[i] -= minn;
    			r[m - i] -= minn;
    			ans++;
    		}
    		else if(i == m - i)
    		{
    			r[i] -= minn;
    			ans++;
    		}
    		ans += r[i] + r[m - i];
    	}
    	printf("%d\n", ans);
    }
    return 0;
}
