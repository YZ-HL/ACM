#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 2005
using namespace std;
struct Edge{
    int u;
    int v;
    int w;
} E[maxn*maxn];
int n, e_cnt, uset[maxn];
char str[maxn][maxn];
int find(int x){
    return uset[x] == x ? uset[x] : uset[x] = find(uset[x]);
}
inline void Build(int u, int v, int w, int i){
    E[i].u = u;
    E[i].v = v;
    E[i].w = w;
}
inline int calc(int pos1, int pos2){
    int len = 7;
    int cnt = 0;
    for (register int i = 0; i <= len - 1; i++)
        if(str[pos1][i] != str[pos2][i])
            cnt++;
    return cnt;
}
inline bool cmp(const Edge &A, const Edge &B){
    return A.w < B.w;
}
inline int Kruskal(){
    int sum = 0, cnt = 0;
    for (register int i = 1; i <= e_cnt; i++)
    {
        int fu = find(E[i].u);
        int fv = find(E[i].v);
        if(fu == fv)
            continue;
        uset[fu] = fv;
        cnt++;
        sum += E[i].w;
        if(cnt == n-1)
            break;
    }
    return sum;
}
int main(void)
{
    while(scanf("%d", &n), n)
    {
        e_cnt = 0;
        for (register int i = 1; i <= n; i++)
        {
            scanf("%s", str[i]);
            uset[i] = i;
        }
        for (register int i = 1; i <= n; i++)
            for (register int j = i+1; j <= n; j++)
            {
                int val = calc(i, j);
                Build(i, j, val, ++e_cnt);
                Build(j, i, val, ++e_cnt);
            }
        sort(E + 1, E + e_cnt + 1, cmp);
        printf("The highest possible quality is 1/%d.\n", Kruskal());
    }
    system("pause");
    return 0;
}
