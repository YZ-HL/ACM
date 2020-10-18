#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 100005
using namespace std;
int t, ans = (1<<30);
char str[maxn];
int now, las[maxn], mapp[maxn];
void inits(){
	mapp['p'] = 1;
	mapp['u'] = 2;
	mapp['l'] = 3;
	mapp['e'] = 4;
	mapp['y'] = 5;
	mapp['a'] = 6;
	mapp['k'] = 7;
	mapp['n'] = 8;
	mapp['o'] = 9;
	mapp['i'] = 10;
}
int main(void)
{
	inits();
    scanf("%d", &t);
    while(t--)
    {
    	now = 0;
    	ans = (1<<30);
    	memset(las, 0, sizeof(las));
    	
    	scanf("%s", str+1);
    	for(int i = 1; str[i]; i++)
    	{
    		if(str[i] == 'p' || str[i] == 'u' || str[i] == 'l' || str[i] == 'e' ||
    		   str[i] == 'y' || str[i] == 'a' || str[i] == 'k' || str[i] == 'n' ||
    		   str[i] == 'o' || str[i] == 'i')
    		{
    			if(!las[mapp[str[i]]])	now++;	
    			las[mapp[str[i]]] = i;
    			if(now == 10)
    			{
    				int minn = (1<<30), maxx = -(1<<30);
    				for(int i = 1; i <= 10; i++)
    					minn = min(minn, las[i]), maxx = max(maxx, las[i]);
    				ans = min(ans, maxx - minn + 1);
    			}
    		}
    	}
    	printf("%d\n", ans == (1<<30) ? -1 : ans);
    }
    return 0;
}
