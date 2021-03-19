CF708-Div2-A.cpp#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn], used[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
    	memset(used, 0, sizeof(used));
    	scanf("%d", &n);
    	for(int i = 1; i <= n; i++)
    		scanf("%d", &a[i]);
    	sort(a + 1, a + n + 1);
    	for(int i = 1; i <= n; i++)
    	{
    		if(!used[a[i]])
    		{ 
    			printf("%d ", a[i]);
    		}
    		used[a[i]]++;
    	}
    	for(int i = 100; i >= 0; i--)
    	{
    		while(used[i] > 1)
    			printf("%d ", i), used[i]--;
    	}
    	putchar('\n');
    }
    return 0;
}
