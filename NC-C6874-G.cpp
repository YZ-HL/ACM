#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000005
using namespace std;
int n, knum, inum, nnum, gnum;
string str;
int main(void)
{
    cin >> n;
    cin >> str;
    int len = str.length();
    for(int i = 0; i <= len-1; i++)
    {
        if(str[i] == 'k')    knum++;
        if(str[i] == 'i')    inum++;
        if(str[i] == 'n')    nnum++;
        if(str[i] == 'g')    gnum++;
    }
    int ans = 0;
    int minn = min(knum, (min(inum, min(nnum, gnum)))/2);
    ans += minn*2;
    knum -= minn;
    inum -= minn*2;
    nnum -= minn*2;
    gnum -= minn*2;
    int minn2 = min(knum, min(inum, min(nnum, gnum)));
    ans += minn2;
    printf("%d\n", ans);
    return 0;
}
