// Z function
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int len, z[maxn];
string str;
void exkmp(){
    len = str.length();
    for(int i = 1, l = 0, r = 0; i <= len - 1; i++)
    {
        if(i <= r)  z[i] = min(r - i + 1, z[i - 1]);
        while(i + z[i] - 1 < len - 1 && str[z[i]] == str[i + z[i]])    ++z[i];
        if(i + z[i] - 1 > r)    l = i, r = i + z[i] - 1;
    }
}
int main(void)
{
    cin >> str;
    exkmp();
    for(int i = 0; i <= len - 1; i++)
        printf("%d ", z[i]);
    putchar('\n');
    system("pause");
    return 0;
}
