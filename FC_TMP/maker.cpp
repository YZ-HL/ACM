#include <bits/stdc++.h>
#define randoms(a, b) rand()%(b-a+1)+a
using namespace std;
int nk[100005];
int main(void)
{
    srand(time(NULL));
    freopen("data.in", "w", stdout);
    int b = randoms(1, 5);
    printf("%d\n", b); 
    for(int i = 1; i <= b; i++)
    {
    	int k = randoms(1, 5), p = randoms(1, 10);
    	printf("%d %d %d\n", i, k, p);
    	nk[i] = k;
	}
	int s = randoms(1, 5);
	printf("%d\n", s);
	for(int i = 1; i <= s; i++)
	{
		int n = randoms(1, b);
		printf("%d\n", n);
		for(int j = 1; j <= n; j++)
			printf("%d %d\n", j, randoms(1, nk[j]));
		printf("%d\n", randoms(1, 8));
	}
    return 0;
}
