#include <bits/stdc++.h>
using namespace std;
int t;
char str[100005];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int na = 0, nb = 0, nc = 0, nd = 0;
        scanf("%s", str+1);
        for(int i = 1; i <= 4; i++)
        {
            if(str[i] == 'A')    na++;
            if(str[i] == 'B')    nb++;
            if(str[i] == 'C')    nc++;
            if(str[i] == 'D')    nd++;
        }
        if(nd || nc >= 2)
            printf("failed\n");
        else if(!nd && na >= 3)
            printf("sp offer\n");
        else
            printf("offer\n");
    }
    return 0;
}