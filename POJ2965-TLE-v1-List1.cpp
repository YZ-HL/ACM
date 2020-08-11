#pragma GCC optimize(2)
#include <cstdio>
#include <iostream>
#define maxn 5
using namespace std;
int ans, flag, board[maxn][maxn], used[(1 << 18) + 5];
string ansx, ansy;
//由于此处记录了路径因此会爆内存，未修复
//理论上可以用记录父亲节点来缓解这个问题，咕
struct Step
{
    int x;
    int st;
    string posx;
    string posy;
    int bits;
};
struct MQueue{
    int left, right;
    Step q[5000005];
    void pop()			{left++;}
    Step front()		{return q[left];}
    void push(Step inx)	
    {
        ++right;
        q[right].x = inx.x;
        q[right].st = inx.st;
        q[right].posx = inx.posx;
        q[right].posy = inx.posy;
        q[right].bits = inx.bits;
    }
    bool empty()		{return left > right;} 
};
int hash_it()
{
    int e = 1, res = 0;
    for (register int i = 1; i <= 4; i++)
        for (register int j = 1; j <= 4; j++)
        {
            res += e * board[i][j];
            e <<= 1;
        }
    return res;
}
void recover_it(int num)
{
    int cnt = 0;
    for (register int i = 1; i <= 4; i++)
        for (register int j = 1; j <= 4; j++)
        {
            board[i][j] = num & (1 << cnt) ? 1 : 0;
            cnt++;
        }
}
void change_it(int x, int y)
{
    for (register int i = 1; i <= 4; i++)
        board[x][i] ^= 1;
    for (register int i = 1; i <= 4; i++)
        board[i][y] ^= 1;
    board[x][y] ^= 1;
}
void input_it()
{
    for (register int i = 1; i <= 4; i++)
    {
        char tmp[10];
        scanf("%s", tmp + 1);
        for (register int j = 1; j <= 4; j++)
            board[i][j] = tmp[j] == '+' ? 1 : 0;
    }
}
MQueue q1;
void bfs()
{
    q1.left = 1;
    int has = hash_it();
    q1.push((Step){has, 0, "", "", 0});
    cout << q1.front().x << endl;
    while (!q1.empty())
    {
        int tmpx = q1.front().x;
        int tmpst = q1.front().st;
        string tmppx = q1.front().posx;
        string tmppy = q1.front().posy;
        int tmpbits = q1.front().bits;
        q1.pop();
        recover_it(tmpx);
        if (!tmpx)
        {
            ans = tmpst;
            ansx = tmppx;
            ansy = tmppy;
            flag = 1;
            break;
        }
        for (register int i = 1; i <= 4; i++)
            for (register int j = 1; j <= 4; j++)
            {
                if(tmpbits & (1<<(4*(i-1)+j-1)))
                    continue;
                change_it(i, j);
                int res = hash_it();
                change_it(i, j);
                string newpx = tmppx + (char)(i + '0');
                string newpy = tmppy + (char)(j + '0');
                q1.push((Step){res, tmpst + 1, newpx, newpy, tmpbits|(1<<(4*(i-1)+j-1))});
            }
    }
    printf("%d\n", ans);
    for (register int i = 0; i <= ans - 1; i++)
        printf("%d %d\n", ansx[i] - '0', ansy[i] - '0');
}
int main(void)
{
    input_it();
    bfs();
    system("pause");
    return 0;
}