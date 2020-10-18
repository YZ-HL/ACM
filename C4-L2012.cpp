#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define lson(x) (x<<1)
#define rson(x) (x<<1)+1
#define maxn 100005
using namespace std;
int n, m;
int min_heap[maxn];
void shift_down(int x){
	int largest = x;
	if(lson(x) <= n && min_heap[lson(x)] < min_heap[largest])
		largest = lson(x);
	if(rson(x) <= n && min_heap[rson(x)] < min_heap[largest])
		largest = rson(x);
	if(largest != x)
	{
		swap(min_heap[x], min_heap[largest]);
		shift_down(largest);
	}
}
void upload(int x){
	if(x == 1)	return;
	if(min_heap[x] < min_heap[x/2])
	{
		swap(min_heap[x], min_heap[x/2]);
		upload(x/2);
	}
}
int xx, yy;
int calc(string now, int pos){
	int x = 0, f = 1;
	if(now[pos] == '-')    f = -1, pos++;
	while(now[pos] >= '0' && now[pos] <= '9')
		x = x*10 + (now[pos] - '0'), pos++;
	return x*f;
}
int check(string now){
	int idx = now.find("root");
	if(idx != string::npos)	
	{
		xx = calc(now, 0);
		return 1;
	}
	idx = now.find("siblings");
	if(idx != string::npos)	
	{
		xx = calc(now, 0);
		yy = calc(now, now.find("and") + 4);
		return 2;
	}
	idx = now.find("parent");
	if(idx != string::npos)
	{
		xx = calc(now, 0);
		yy = calc(now, now.find("of") + 3);
		return 3;
	}
	xx = calc(now, 0);
	yy = calc(now, now.find("of") + 3);
	return 4;

}
int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &min_heap[i]);
    for(int i = 1; i <= n; i++)
    	upload(i);
    getchar();
    for(int i = 1; i <= m; i++)
    {
    	string tmp;
    	getline(cin, tmp);
    	int val = check(tmp);
    	if(val == 1){
    		putchar(min_heap[1] == xx ? 'T' : 'F');
		}
    	else if(val == 2)
    	{
    		int flag = 0;
    		for(int i = 1; i <= n/2; i++)
    		{
    			if(min_heap[lson(i)] == xx && min_heap[rson(i)] == yy)
    			{
    				flag = 1;
    				break;
    			}
    			if(min_heap[lson(i)] == yy && min_heap[rson(i)] == xx)
    			{
    				flag = 1;
    				break;
    			}
    		}
    		putchar(flag ? 'T' : 'F');
    	}
    	else if(val == 3)
    	{
    		int flag = 0;
    		for(int i = 1; i <= n; i++)
    		{
    			if(min_heap[i] == xx && (min_heap[lson(i)] == yy || min_heap[rson(i)] == yy))
    			{
    				flag = 1;
    				break;
    			}
    		}
    		putchar(flag ? 'T' : 'F');
    	}
    	else
    	{
    		int flag = 0;
    		for(int i = 1; i <= n; i++)
    		{
    			if(min_heap[i] == yy && (min_heap[lson(i)] == xx || min_heap[rson(i)] == xx))
    			{
    				flag = 1;
    				break;
    			}
    		}
    		putchar(flag ? 'T' : 'F');
    	}
    	if(i != m)
    		putchar('\n');
    }
    return 0;
}
