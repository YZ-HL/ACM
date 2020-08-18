#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    string str;
    cin >> str;
    if(str == "RRR")
        printf("%d", 3);
    else if(str == "RRS")
        printf("%d", 2);
    else if(str == "RSR")
        printf("%d", 1);
    else if(str == "SRR")
        printf("%d", 2);
    else if(str == "SSR")
        printf("%d", 1);
    else if(str == "RSS")
        printf("%d", 1);
    else if(str == "SRS")
        printf("%d", 1);
    else if(str == "SSS")
        printf("%d", 0);
    system("pause");
    return 0;
}
