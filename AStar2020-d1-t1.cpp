#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#define eps 1e-7
using namespace std;
int test,ans;
double n,m,p;
int main()
{
	ios::sync_with_stdio(false);
	cin>>test;
	while(test--)
	{
		ans=0;
		cin>>n>>m>>p;
		p/=(double)100;
		while(n-m>eps)
		{
			ans++;
			double k=n;
			k-=m;
			k+=floor(n*(1-p));
			n=k;
		}
		cout<<ans<<endl;
	}
 }
