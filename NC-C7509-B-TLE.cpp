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
int now, pos[11][maxn], mapp[maxn], sat[11][maxn];
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
void dfs(int now, int poss, int s){
	if(ans == 10)
		return;
	if(now == 11)
	{
		ans = min(ans, poss - s + 1);
		return;
	}
	if(poss - s + 1 > ans)
		return;
		
	for(register int i = max((int)(upper_bound(pos[now]+1, pos[now]+pos[now][0]+1, poss) - (pos[now] + 1)), 1); i <= pos[now][0]; i++)
	{
		//printf("%d %d %d %d\n", i, now, poss, pos[now][i]);
		if(pos[now][i] > poss)
			dfs(now + 1, pos[now][i], now == 1 ? pos[now][i] : s);
	}
}
int main(void)
{
	inits();
    scanf("%d", &t);
    while(t--)
    {
    	now = 0;
    	ans = (1<<30);
    	for(int i = 1; i <= 10; i++)	pos[i][0] = 0;
    	
    	scanf("%s", str+1);
    	for(register int i = 1; str[i]; i++)
    	{
    		if(str[i] == 'p' || str[i] == 'u' || str[i] == 'l' || str[i] == 'e' ||
    		   str[i] == 'y' || str[i] == 'a' || str[i] == 'k' || str[i] == 'n' ||
    		   str[i] == 'o' || str[i] == 'i')
    		{
    			pos[mapp[str[i]]][++pos[mapp[str[i]]][0]] = i;
    		}
    	}
    	dfs(1, 0, 0);
    	printf("%d\n", ans == (1<<30) ? -1 : ans);
    }
    return 0;
}
