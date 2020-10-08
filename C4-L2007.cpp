#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
int n, other, uset[maxn];
int cnt, vis[maxn];
map<string, int> str_to_int;
struct Family{
	string min_num = "9999";
	int num, all_num_h, all_area;
} F[maxn];
struct Input{
	string num, num_f, num_m;
	string chi[10];
	int k, num_h, all_a;
} info[maxn];
bool cmp(const Family &A, const Family &B){
	double avg_A = 1.0*A.all_area/A.num;
	double avg_B = 1.0*B.all_area/B.num;
	if(avg_A != avg_B)
		return avg_A > avg_B;
	return A.min_num < B.min_num;
}
int find(int x){
	return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unionn(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if(fx == fy)
		return;
	uset[fx] = fy;
}
int main(void)
{
	//std::ios::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i <= maxn-5; i++)
		uset[i] = i;
	for(int i = 1; i <= n; i++)
	{
		cin >> info[i].num >> info[i].num_f >> info[i].num_m;
		cin >> info[i].k;
		for(int j = 1; j <= info[i].k; j++)
			cin >> info[i].chi[j];
		cin >> info[i].num_h >> info[i].all_a;
		str_to_int[info[i].num] = i;
    }
    for(int i = 1; i <= n; i++)
    {
    	int m = i;
    	
    	if(info[i].num_f != "-1" && !str_to_int.count(info[i].num_f))
    	{
    		str_to_int[info[i].num_f] = n + (++other);
    		info[n + other].num = info[i].num_f;
    		unionn(m, str_to_int[info[i].num_f]);
    	}
    	else if(info[i].num_f != "-1")
    		unionn(m, str_to_int[info[i].num_f]);
    	
    	if(info[i].num_m != "-1" && !str_to_int.count(info[i].num_m))
    	{
    		str_to_int[info[i].num_m] = n + (++other);
    		info[n + other].num = info[i].num_m;
    		unionn(m, str_to_int[info[i].num_m]);
    	}
    	else if(info[i].num_m != "-1")
    		unionn(m, str_to_int[info[i].num_m]);
    	
    	for(int j = 1; j <= info[i].k; j++)
    	{
    		if(!str_to_int[info[i].chi[j]])
    		{
    			str_to_int[info[i].chi[j]] = n + (++other);
    			info[n + other].num = info[i].chi[j];
    			unionn(m, str_to_int[info[i].chi[j]]);
    		}
    		else
    			unionn(m, str_to_int[info[i].chi[j]]);
    	}
    }
    for(int i = 1; i <= n + other; i++)
    {
    	int fa = find(i);
    	if(!vis[fa])	vis[fa] = ++cnt;
    	F[vis[fa]].min_num = min(F[vis[fa]].min_num, info[i].num);
    	F[vis[fa]].num++;
    	F[vis[fa]].all_num_h += info[i].num_h;
    	F[vis[fa]].all_area += info[i].all_a;
    }
    sort(F+1, F+cnt+1, cmp);
    cout << cnt << endl;
    for(int i = 1; i <= cnt; i++)
    {
    	cout << F[i].min_num << " " << F[i].num << " ";
    	printf("%.3lf %.3lf", 1.0*F[i].all_num_h/F[i].num, 1.0*F[i].all_area/F[i].num);
    	if(i != cnt)	putchar('\n');
    }
    return 0;
}
