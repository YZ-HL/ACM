#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int a, b, n, m, flag;
int posx[maxn], posy[maxn];
struct robot{
    int x;
    int y;
    char ch;
}r[maxn];
char turn(char r, char n){
    if(r == 'N' && n == 'L')
        return 'W';
    if(r == 'E' && n == 'L')
        return 'N';
    if(r == 'S' && n == 'L')
        return 'E';
    if(r == 'W' && n == 'L')
        return 'S';
    if(r == 'N' && n == 'R')
        return 'E';
    if(r == 'E' && n == 'R')
        return 'S';
    if(r == 'S' && n == 'R')
        return 'W';
    if(r == 'W' && n == 'R')
        return 'N';
    return 'E';
}
void inits(){
    posx['N'] = 0;
    posx['E'] = 1;
    posx['S'] = 0;
    posx['W'] = -1;
    posy['N'] = 1;
    posy['E'] = 0;
    posy['S'] = -1;
    posy['W'] = 0;
}
void check(int num, int x, int y){
    if (x == 0 || y == 0 || x == a+1 || y == b+1)
    {
        printf("Robot %d crashes into the wall\n", num);
        flag = 1;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if(r[i].x == x && r[i].y == y && i != num)
        {
            printf("Robot %d crashes into robot %d\n", num, i);
            flag = 1;
            return;
        }
    }
}
void carry(int num, char pos, int rep){
    if(pos == 'L' || pos == 'R')
    {
        for(int i = 1; i <= rep; i++)
            r[num].ch = turn(r[num].ch, pos);
        return;
    }
    for (int i = 1; i <= rep; i++)
    {
        r[num].x += posx[r[num].ch];
        r[num].y += posy[r[num].ch];
        check(num, r[num].x, r[num].y);
        if(flag)    return;
    }
}
int main(void)
{
    int t;
    scanf("%d", &t);
    inits();
    while(t--)
    {
        flag = 0;
        scanf("%d %d", &a, &b);
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d %d %c", &r[i].x, &r[i].y, &r[i].ch);
        for (int i = 1; i <= m; i++)
        {
            int num, rep; char com;
            scanf("%d %c %d", &num, &com, &rep);
            if(!flag)
                carry(num, com, rep);
        }
        if(!flag)
            printf("OK\n");
    }
    system("pause");
    return 0;
}
