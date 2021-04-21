#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
char get_char(){
    char ch = getchar();
    while(ch != 'W' && ch != 'B' && ch != 'R')    ch = getchar();
    return ch;
}
int mp[maxn];
int main(void)
{
    mp['R'] = 1;
    mp['B'] = 2;
    mp['W'] = 3;
    
    scanf("%d", &n);
    int flag = 0;
    char now, las = '#', lf = '*', flg = 1;
    for(int i = 1; i <= n; i++)
    {
        char now = get_char();
        if(flg)    
        {
            lf = now;
            flg = 0;
        }
        if(now == 'R')    flag ^= 1;
        if(now == 'B')    flag ^= 2;
        if(now == 'W')    flag ^= 3;
       
        if(flag == 0)   
        {
            flag ^= (mp[lf] ^ mp[now]);
            flg = 1;
        }
    }
    if(flag == 3)
        printf("W\n");
    else if(flag == 2)
        printf("B\n");
    else
        printf("R\n");
    return 0;
}
