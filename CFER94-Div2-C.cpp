#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int t, x, len, w[maxn];
string str;
void check(int pos, char s){
    if(s == '0')
    {
        if(pos > x)
            w[pos - x] = 0;
        if(pos <= len-x)
            w[pos + x] = 0;
    }
    if(s == '1')
    {
        if(pos > x)
            w[pos - x] = 1;
        if(pos <= len-x)
            w[pos + x] = 1;
    }
}
int check_va(int pos){
    int res = 0;
    if(pos > x)
        res |= w[pos - x];
    if(pos <= len-x)
        res |= w[pos + x];
    return res;
}
int main(void)
{
    cin >> t;
    while(t--)
    {
        memset(w, 0, sizeof(w));

        cin >> str;
        cin >> x;
        len = str.length();
        for (int i = 0; i <= len-1; i++)
            if(str[i] == '1')   check(i+1, str[i]);
        for (int i = 0; i <= len-1; i++)
            if(str[i] == '0')   check(i+1, str[i]);

        int flag = 1;
        for (int i = 0; i <= len-1; i++)
            if(str[i] == '1')   flag &= check_va(i+1);
        
        if(flag)
            for (int i = 1; i <= len; i++)
                printf("%d", w[i]);
        else
            printf("-1");
        putchar('\n');
    }
    system("pause");
    return 0;
}
