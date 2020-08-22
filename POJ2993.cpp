#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 105
using namespace std;
string whi, bla;
char board[maxn][maxn];
void work()
{
    int len1 = whi.length();
    int len2 = bla.length();
    string tmp = "";
    for (int i = 7; i <= len1; i++)
    {
        if (i == len1 || whi[i] == ',')
        {
            if (tmp.length() == 3)
                board[tmp[2] - '0'][tmp[1] - 'a' + 1] = tmp[0];
            else
                board[tmp[1] - '0'][tmp[0] - 'a' + 1] = 'P';
            tmp = "";
            continue;
        }
        tmp += whi[i];
    }
    for (int i = 7; i <= len2; i++)
    {
        if (i == len2 || bla[i] == ',')
        {
            if (tmp.length() == 3)
                board[tmp[2] - '0'][tmp[1] - 'a' + 1] = ('a' + (tmp[0] - 'A'));
            else
                board[tmp[1] - '0'][tmp[0] - 'a' + 1] = 'p';
            tmp = "";
            continue;
        }
        tmp += bla[i];
    }
}
void print()
{
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int i = 8; i >= 1; i--)
    {
        for (int j = 1; j <= 8; j++)
        {
            putchar('|');
            if ((i + j) & 1)
            {
                putchar('.');
                putchar(board[i][j] ? board[i][j] : '.');
                putchar('.');   
            }
            else
            {
                putchar(':');
                putchar(board[i][j] ? board[i][j] : ':');
                putchar(':');
            }
        }
        printf("|\n+---+---+---+---+---+---+---+---+\n");
    }
}
int main(void)
{
    getline(cin, whi);
    getline(cin, bla);
    work();
    print();
    system("pause");
    return 0;
}
