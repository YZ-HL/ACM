#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define int long long 
using namespace std;
int n,a[100005],num,sum,maxx=-1,ans;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int id;
	for(int i=1;i<=n;i++)
	{
		maxx=a[1];
		num++;
		if(num>=maxx)
		{
			num=0;
			ans++;
			id=i+1;
			break;
		}
	}
	if(ans==0)
	{
		cout<<"-1";
		return 0;
	}
	//cout<<id<<endl;
	maxx=-1;
	for(int i=n;i>=id;i--)
	{
		maxx=max(maxx,a[i]);
		num++;
		if(num>=maxx)
		{
			ans++;
			maxx=-1;
			num=0;
		}
	}
	cout<<ans;
}
