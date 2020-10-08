#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int vis[maxn];
struct Point{
	int val;
	string t;
	bool flag;
} P[maxn];
unordered_map<string, Point> m1;
int main(void)
{
	std::ios::sync_with_stdio(false); 
	
	int n;
    string start;
    cin >> start >> n;
	for(int i = 1; i <= n; i++)
	{
		int val;
		string s, t;
		cin >> s >> val >> t;
		m1[s] = (Point){val, t, true};
	}
	string now = start;
	while(now != "-1")
	{
		Point p = m1[now];
		if(!vis[abs(p.val)])
			cout << now << " " << m1[now].val << " ";
		vis[abs(p.val)] = 1;
		now = m1[now].t;
		while(vis[abs(m1[now].val)] && now != "-1")    
		{
			m1[now].flag = false;
			now = m1[now].t;
		}
		cout << now << endl;
	}
	int firs = 0;
	now = start;
	while(now != "-1")
	{
		if(!m1[now].flag)
		{
			if(!firs)
			{
				cout << now << " " << m1[now].val << " ";
				firs = 1;
			}
			else
				cout << now << endl << now << " " << m1[now].val << " ";
		}
		now = m1[now].t;
	}
	if(firs)	cout << "-1";
    return 0;
}
