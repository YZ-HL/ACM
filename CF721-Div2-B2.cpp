#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
string str;
void solveB1(int cnt1, int cnt0, int len){
    if(cnt0 == 1)
        printf("BOB\n");
    else if(cnt0 % 2)
        printf("ALICE\n");
    else
        printf("BOB\n");
}
int main(void)
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> str;
        int len = str.length();
        int cnt1 = 0, cnt0 = 0, isp = 1;
        for(int i = 0; i < len; i++)    cnt0 += (str[i] == '0');
        for(int i = 0; i < len / 2; i++)
        {
            if(str[i] != str[len - i - 1])    
            {
                isp = 0;
                cnt1++;
            }
        }
        if(isp)
            solveB1(cnt1, cnt0, len);
        else
            printf(cnt1 == 1 && cnt0 == 2 ? "DRAW\n" : "ALICE\n");
    }
    return 0;
}

