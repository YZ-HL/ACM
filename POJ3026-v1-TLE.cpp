#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 55
using namespace std;
int xx, yy;
int cnt, cnt_e, nx[maxn*maxn], ny[maxn*maxn], vis[maxn][maxn];
int sf[maxn][maxn];
char board[maxn][maxn];
int posx[] = {0, 0, 0, 1, -1};
int posy[] = {0, 1, -1, 0, 0};
int uset[maxn];
struct Edge{
    int u;
    int v;
    int w;
} E[maxn*maxn];
struct P{
    int x;
    int y;
    int dis;
};
bool operator < (const Edge &A, const Edge &B){
    return A.w < B.w;
}
inline void Build(int u, int v, int w, int n){
    E[n].u = u;
    E[n].v = v;
    E[n].w = w;
}
inline int find(int x){
    return x == uset[x] ? uset[x] : uset[x] = find(uset[x]);
}
inline void unionn(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)
        return;
    uset[fx] = fy;
}
inline bool check(int x, int y, int p){
    if(x + posx[p] > xx || x + posx[p] < 1) return false;
    if(y + posy[p] > yy || y + posy[p] < 1) return false;
    
    return board[x + posx[p]][y + posy[p]] != '#';
}
inline void bfs(int s){
    memset(vis, 0, sizeof(vis));

    queue<P> q1;
    q1.push((P){nx[s], ny[s], 0});
    while(!q1.empty())
    {
        P tmp = q1.front();
        //printf("debug: %d %d\n", tmp.x, tmp.y);
        q1.pop();
        vis[tmp.x][tmp.y] = 1;
        if((board[tmp.x][tmp.y] == 'A' || board[tmp.x][tmp.y] == 'S') && (tmp.x != nx[s] || tmp.y != ny[s]))
        {
            //printf("debug: %d %d %d\n", s, sf[tmp.x][tmp.y], tmp.dis);
            Build(s, sf[tmp.x][tmp.y], tmp.dis, ++cnt_e);
            Build(sf[tmp.x][tmp.y], s, tmp.dis, ++cnt_e);
        }
        for (register int i = 1; i <= 4; i++)
            if(check(tmp.x, tmp.y, i) && !vis[tmp.x + posx[i]][tmp.y + posy[i]])
                q1.push((P){tmp.x + posx[i], tmp.y + posy[i], tmp.dis + 1});
    }
    //system("pause");
}
inline int Kruskal(){
    int c = 0, sum = 0;
    for (register int i = 1; i <= cnt_e; i++)
    {
        int fx = find(E[i].u);
        int fy = find(E[i].v);
        if(fx == fy)
            continue;
        c++;
        sum += E[i].w;
        unionn(fx, fy);
        if(c == cnt)
            break;
    }
    return sum;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        cnt = 0;
        cnt_e = 0;

        scanf("%d %d", &xx, &yy);
        for (register int i = 1; i <= yy; i++)
        {
            while (getchar() != '\n');
            for (register int j = 1; j <= xx; j++)
            {
                board[i][j] = getchar();
                if(board[i][j] == 'S')
                {
                    nx[0] = i;
                    ny[0] = j;

                    sf[i][j] = 0;
                }
                if (board[i][j] == 'A')
                {
                    cnt++;
                    nx[cnt] = i;
                    ny[cnt] = j;

                    sf[i][j] = cnt;
                }
            }
        }
        for (register int i = 0; i <= cnt; i++)  uset[i] = i;
        for (register int i = 0; i <= cnt; i++)
            bfs(i);
        sort(E + 1, E + cnt_e + 1);
        printf("%d\n", Kruskal());
    }
    system("pause");
    return 0;
}
