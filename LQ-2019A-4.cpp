#include <bits/stdc++.h>
#define maxn 55
using namespace std;
char board[maxn][maxn];
char qread(){
    char ch = getchar();
    while(ch != '0' && ch != '1')   ch = getchar();
    return ch;
}
struct Step{
    int x, y;
    int num;
    string detail;
};
bool operator < (const Step &A, const Step &B){
    return A.x == B.x ? A.y < B.y : A.x < B.x;
}
set<Step> s1;
queue<Step> q1;
int fx[] = {0, 1, 0, 0, -1};
int fy[] = {0, 0, -1, 1, 0};
char d[] = {'#', 'D', 'L', 'R', 'U'};
string bfs(){
    q1.push((Step){1, 1, 0, ""});
    s1.insert((Step){1, 1, 0, ""});
    while(!q1.empty())
    {
        Step tmp = q1.front(); q1.pop();
        if(tmp.x == 4 && tmp.y == 6)
        {
            return tmp.detail;
        }
        for(int i = 1; i <= 4; i++)
        {
            int nx = tmp.x + fx[i];
            int ny = tmp.y + fy[i];
            int ns = tmp.num + 1;
            string nd = tmp.detail + d[i];
            if(board[nx][ny] == '1')    continue;
            if(nx < 1 || ny < 1 || nx > 4 || ny > 6)  continue;
            if(!s1.count((Step){nx, ny, ns, nd}))
            {
                s1.insert((Step){nx, ny, ns, nd});
                q1.push((Step){nx, ny, ns, nd});
            }
        }
    }
    return "NULL";
}
int main(void)
{
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 6; j++)
            board[i][j] = qread();
    cout << bfs() << endl;
    return 0;
}