#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n;
string str;
int main(void)
{
    scanf("%d", &n);
    cin >> str;
    int len = str.length();
    int maxx = 0, cnt = 0;
    for(int i = 0; i < len; i++)
        if(str[i] == 'P')
            cnt++;
    maxx = max(maxx, cnt);
    cnt = 0;
    for(int i = 0; i < len; i++)
        if(str[i] == 'R')
            cnt++;
    maxx = max(maxx, cnt);
    cnt = 0;
    for(int i = 0; i < len; i++)
        if(str[i] == 'S')
            cnt++;
    maxx = max(maxx, cnt);
    printf("%d\n", maxx);
    return 0;
}