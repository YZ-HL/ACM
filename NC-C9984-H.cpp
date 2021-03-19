#include <bits/stdc++.h>
#define maxn 200005
#define int long long
const int mod = 1e9 + 7;
using namespace std;
struct Edge{
    int to;
    int nxt;
    char w;
} E[maxn];
struct Point{
    int v1;
    int v2;
    int f;
} P[maxn];
int ans[maxn];
int n, k, fa[maxn], val[maxn], head[maxn];
char op[maxn];
void Build(int u, int v, char w){
    E[k].to = v;
    E[k].nxt = head[u];
    E[k].w = w;
    head[u] = k++;
}
char get_read(){
    char ch = getchar();
    while(ch != '+' && ch != '-' && ch != '*' && ch != '/')
        ch = getchar();
    return ch;
}
int qpow(int a, int b, int p){
    if(b == 0)    return 1;
    int tmp = qpow(a, b / 2, p);
    tmp = (tmp * tmp) % p;
    if(b & 1)    tmp = (tmp * a) % p;
    return tmp;
}
int inv(int x){
    return qpow(x, mod - 2, mod);
}
void dfs(int rt, int fa, char op){
	if(op == '+')
		P[rt].v1 = P[fa].f == 1 ? (P[fa].v1 + P[fa].v2) % mod : (P[fa].v1 - P[fa].v2) % mod, P[rt].v2 = val[rt], P[rt].f = 1;
	if(op == '-')
		P[rt].v1 = P[fa].f == 1 ? (P[fa].v1 + P[fa].v2) % mod : (P[fa].v1 - P[fa].v2) % mod, P[rt].v2 = val[rt], P[rt].f = -1;
	if(op == '*')
		P[rt].v1 = P[fa].v1, P[rt].v2 = (P[fa].v2 * val[rt]) % mod, P[rt].f = P[fa].f;
	if(op == '/')
		P[rt].v1 = P[fa].v1, P[rt].v2 = (P[fa].v2 * inv(val[rt])) % mod, P[rt].f = P[fa].f;
	for(int i = head[rt]; ~i; i = E[i].nxt)
	{
		if(E[i].to == fa)	continue;
		dfs(E[i].to, rt, E[i].w);
	}
}
signed main(void)
{
	memset(head, -1, sizeof(head));
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &val[i]);
    for(int i = 1; i <= n - 1; i++)
        scanf("%lld", &fa[i]);
    for(int i = 1; i <= n - 1; i++)
        op[i] = get_read();
    for(int i = 1; i <= n - 1; i++)
        Build(fa[i], i + 1, op[i]);
    P[1].v1 = 0, P[1].v2 = val[1]; P[1].f = 1;
    dfs(1, 0, '#');
    /*
    for(int i = 1; i <= n; i++)
    	printf("%lf %lf %lf\n", P[i].v1, P[i].v2, P[i].f);
    */
    for(int i = 1; i <= n; i++)
    	printf("%d ", P[i].f == 1 ? (((P[i].v1 + P[i].v2) % mod) + mod) % mod : (((P[i].v1 - P[i].v2) % mod) + mod) % mod);
	return 0;
}