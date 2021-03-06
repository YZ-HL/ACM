#include <bits/stdc++.h>
const int N = 1e6 + 5;
using namespace std;
int n, onum, vnum;
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        (tmp & 1) ? onum++ : vnum++;
    }
    int win = 0;
    if(n == 1)
        onum ? win = 1 : win = 0;
    else
    {
        if(n & 1)
            win = 0;
        else
            vnum >= 2 ? win = 0 : win = 1;
    }
    printf(win ? "NiuNiu" : "NiuMei");
    return 0;
}