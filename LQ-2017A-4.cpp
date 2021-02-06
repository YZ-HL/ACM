#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct Snack{
    int x;
    int y;
    string sta;
    int num;
};
bool operator < (const Snack &A, const Snack &B){
    return A.sta < B.sta;
}
set<Snack> s1;
queue<Snack> q1;
int fx[] = {0, 1, -1, 0, 0};
int fy[] = {0, 0, 0, 1, -1};
int calc(int x, int y){
    return 6 * (x - 1) + y;
}
bool check(string now, int x, int y, int f){
    int nowx = x + fx[f];
    int nowy = y + fy[f];
    if(nowx < 1 || nowy < 1 || nowx > 6 || nowy > 6)
        return false;
    if(now[calc(nowx, nowy)] != '0' || now[calc(7 - nowx, 7 - nowy)] != '0')
        return false;
    now[calc(nowx, nowy)] = '1';
    now[calc(7 - nowx, 7 - nowy)] = '2';
    if(s1.count((Snack){nowx, nowy, now, 0}))
        return false;
    return true;
}
set<string> AnsCnt;
bool CheckAns(string now){
    string tmp = now;
    bool flag = true;
    for(int k = 1; k <= 4; k++)
    {
        for(int i = 1; i <= 6; i++)
            for(int j = 1; j <= 6; j++)
                tmp[calc(i, j)] = now[calc(7 - j, i)];
        if(AnsCnt.count(tmp))
            flag = false;
        now = tmp;
    }
    return flag;
}
void bfs(){
    Snack init = (Snack){1, 1, "#100000000000000000000000000000000002", 1};
    s1.insert(init);
    q1.push(init);
    int ans = 0;
    while(!q1.empty())
    {
        Snack now = q1.front(); q1.pop();
        if(now.num == 18)
        {
            if(CheckAns(now.sta))
            {
                ans++;
                AnsCnt.insert(now.sta);
                /*
                printf("gg\n");

                for(int i = 1; i <= 6; i++)
                    for(int j = 1; j <= 6; j++)
                        printf(j == 6 ? "%c\n" : "%c", now.sta[calc(i, j)]);
                
                system("Pause");
                */
            }
            continue;
        }
        for(int i = 1; i <= 4; i++)
            if(check(now.sta, now.x, now.y, i))
            {
                string tmp = now.sta;
                int nowx = now.x + fx[i];
                int nowy = now.y + fy[i];
                tmp[calc(nowx, nowy)] = '1';
                tmp[calc(7 - nowx, 7 - nowy)] = '2';
                s1.insert((Snack){nowx, nowy, tmp, now.num + 1});
                q1.push((Snack){nowx, nowy, tmp, now.num + 1});
            }
    }
    printf("%d\n", ans);
}
int main(void)
{
    bfs();
    //printf("%d\n", 31);
    return 0;
}
