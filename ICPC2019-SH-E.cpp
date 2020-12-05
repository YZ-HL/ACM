#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1505
using namespace std;
int t, n, m, sr, sc, tr, tc, cases;
int seq[maxn * maxn], val[maxn][maxn], a, b, c, p;
int eds, uset[maxn * maxn];
struct Edge{
    int u;
    int v;
    int w;
} E[maxn * maxn];
bool cmp(const Edge &A, const Edge &B){
    return A.w > B.w;
}
int read(){
    int x = 0,f = 1;	char ch = getchar();
    while (ch < '0' || ch > '9')		{if(ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9')		{x = x*10+ch-'0';  	   ch = getchar();}
    return x*f;
}
int find(int x){
    return x == uset[x] ? x : uset[x] = find(uset[x]);
}
void unionn(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    uset[fx] = fy;
}
long long Krus(){
    sort(E + 1, E + eds + 1, cmp);
    int cnt = 0, now = 1;
    long long sum = 0;
    while (cnt < n * m - 1)
    {
        //printf("%lld %lld %lld\n", E[now].u, E[now].v, E[now].w);
        //system("pause");
        int fu = find(E[now].u);
        int fv = find(E[now].v);
        if (fu == fv)
        {
            now++;
            continue;
        }
        sum += E[now].w;
        unionn(E[now].u, E[now].v); cnt++; now++;
    }
    return sum;
}
void Build(int u, int v, int w){
    eds++;
    E[eds].u = u;
    E[eds].v = v;
    E[eds].w = w;
}
signed main(void)
{
    scanf("%d", &t);
    while (t--)
    {
        eds = 0;
        //memset(E, 0, sizeof(E));
        n = read(); m = read(); sr = read(); sc = read(); tr = read(); tc = read();
        seq[1] = read(); seq[2] = read(); a = read(); b = read(); c = read(); p = read();
        
        //scanf("%d %d %d %d %d %d", &n, &m, &sr, &sc, &tr, &tc);
        //scanf("%d %d %d %d %d %d", &seq[1], &seq[2], &a, &b, &c, &p);

        for (int i = 3; i <= n * m; i++)
            seq[i] = (a * seq[i - 1] + b * seq[i - 2] + c) % p;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                int now = (i - 1) * m + j;
                val[i][j] = seq[now];
                uset[now] = now;
                if (j != 1)
                    Build((i - 1) * m + j, (i - 1) * m + j - 1, val[i][j] * val[i][j - 1]);
                if (i != 1)
                    Build((i - 1) * m + j, (i - 2) * m + j, val[i][j] * val[i - 1][j]);
            }
        /*
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (j != 1)
                    Build((i - 1) * m + j, (i - 1) * m + j - 1, val[i][j] * val[i][j - 1]);
                if (i != 1)
                    Build((i - 1) * m + j, (i - 2) * m + j, val[i][j] * val[i - 1][j]);
            }
        */
        printf("Case #%d: %lld\n", ++cases, Krus());
    }
    return 0;
}
