#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
using namespace std;
int n, len1, len2;
char str[maxn];
char pre[maxn], suf[maxn];
bool check(){
    for(int i = 0; str[i] != '#'; i++)
    {
        if(i >= len1)
            pre[len1++] = str[i];
        else if(pre[i] != str[i])
            return true;
    }
    int ed = strlen(str) - 1;
    for(int i = ed; str[i] != '#'; i--)
    {
        if(ed - i >= len2)
            suf[len2++] = str[i];
        else if(suf[ed - i] != str[i])
            return true;
    }
    return false;
}
int main(void)
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        if(check())
        {
            printf("0\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}