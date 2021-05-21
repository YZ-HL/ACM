#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        string str;
        cin >> str;
        int len = str.length(), cnt1 = 0, cnt0 = 0;
        for(int i = 0; i < len; i++)
            str[i] == '0' ? cnt0++ : cnt1++;
        if((len & 1) && str[len / 2] == '0')
        {
            cnt0--;
            if(cnt0 == 1)
                printf("DRAW\n");
            else if(cnt0 == 0)
                printf("BOB\n"); 
            else 
                printf("ALICE\n");
                  
        }
        else
        {
            if(cnt0 == 0)
                printf("DRAW\n");
            else
                printf("BOB\n");
        }
    }
    return 0;
}
