#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, k = 3;
int main(void)
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		if(n & 1)
			printf("%d %d %d\n", n / 2, n / 2, 1);
		else if((n / 2) & 1)
			printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
		else
			printf("%d %d %d\n", n / 2, n / 4, n / 4);
	}
    return 0;
}
