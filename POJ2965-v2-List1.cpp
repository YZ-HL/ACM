#include <cstdio>
#include <iostream>
using namespace std;
int board[5][5], res[5][5];
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
void change_it(int x, int y)
{
    for (register int i = 1; i <= 4; i++)
        res[x][i]++;
    for (register int i = 1; i <= 4; i++)
        res[i][y]++;
    res[x][y]--;
}
int main(void)
{
    input_it();
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if(board[i][j])
                change_it(i, j);
    int ans = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if(res[i][j] & 1)
                ans++;
    printf("%d\n", ans);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if(res[i][j] & 1)
                printf("%d %d\n", i, j);
    system("pause");
    return 0;
}