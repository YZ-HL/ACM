#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 105
using namespace std;
string tmp;
char board[maxn][maxn];
int cnt1, cnt2;
struct Bo{
    int val;
    int x;
    int y;
}whi[maxn], bla[maxn];
int valcheck(char x){
    if(x == 'K' || x == 'k')
        return 7;
    if(x == 'Q' || x == 'q')
        return 6;
    if(x == 'R' || x == 'r')
        return 5;
    if(x == 'B' || x == 'b')
        return 4;
    if(x == 'N' || x == 'n')
        return 3;
    return 2;
}
bool cmp_w(const Bo &A, const Bo &B){
    if(A.val != B.val)
        return A.val > B.val;
    if(A.y != B.y)
        return A.y < B.y;
    return A.x < B.x;
}
bool cmp_b(const Bo &A, const Bo &B){
    if(A.val != B.val)
        return A.val > B.val;
    if(A.y != B.y)
        return A.y > B.y;
    return A.x < B.x;
}
bool check(char x){
    if(x >= 'a' && x <= 'z')
        return true;
    if(x >= 'A' && x <= 'Z')
        return true;
    return false;
}
char returnchar(int val, int color){
    if(val == 7)
        return color ? 'K' : 'k';
    if(val == 6)
        return color ? 'Q' : 'q';
    if(val == 5)
        return color ? 'R' : 'r';
    if(val == 4)
        return color ? 'B' : 'b';
    if(val == 3)
        return color ? 'N' : 'n';
    return '*';
}
int main(void)
{
    for (int i = 1; i <= 8; i++)
    {
        getline(cin, tmp);
        getline(cin, tmp);
        int cnt = 0, len = tmp.length();
        for (int j = 0; j <= len - 1; j++)
        {
            if(tmp[j] == '|')
                cnt++;
            if(check(tmp[j]))
                board[i][cnt] = tmp[j];
        }
    }
    getline(cin, tmp);
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            if(board[i][j] && board[i][j] >= 'a' && board[i][j] <= 'z')
            {
                ++cnt1;
                bla[cnt1].val = valcheck(board[i][j]);
                bla[cnt1].x = j;
                bla[cnt1].y = 8-i+1;
            }
            if(board[i][j] && board[i][j] >= 'A' && board[i][j] <= 'Z')
            {
                ++cnt2;
                whi[cnt2].val = valcheck(board[i][j]);
                whi[cnt2].x = j;
                whi[cnt2].y = 8-i+1;
            }
        }
    sort(bla + 1, bla + cnt1 + 1, cmp_b);
    sort(whi + 1, whi + cnt2 + 1, cmp_w);

    printf("White: ");
    for (int i = 1; i <= cnt1-1; i++)
        returnchar(whi[i].val, 1) != '*' ? printf("%c%c%d,", returnchar(whi[i].val, 1), whi[i].x + 'a' - 1, whi[i].y) : printf("%c%d,", whi[i].x + 'a' - 1, whi[i].y);
    returnchar(whi[cnt1].val, 1) != '*' ? printf("%c%c%d\n", returnchar(whi[cnt1].val, 1), whi[cnt1].x + 'a' - 1, whi[cnt1].y) : printf("%c%d\n", whi[cnt1].x + 'a' - 1, whi[cnt1].y);

    printf("Black: ");
    for (int i = 1; i <= cnt2-1; i++)
        returnchar(bla[i].val, 1) != '*' ? printf("%c%c%d,", returnchar(bla[i].val, 1), bla[i].x + 'a' - 1, bla[i].y) : printf("%c%d,", bla[i].x + 'a' - 1, bla[i].y);
    returnchar(bla[cnt2].val, 1) != '*' ? printf("%c%c%d\n", returnchar(bla[cnt2].val, 1), bla[cnt2].x + 'a' - 1, bla[cnt2].y) : printf("%c%d\n", bla[cnt2].x + 'a' - 1, bla[cnt2].y);
    
    system("pause");
    return 0;
}
