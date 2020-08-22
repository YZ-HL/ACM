#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int cnt = 0;
    do{
        printf("Case #%d:\n", ++cnt);
        system("maker.exe");
        system("my.exe < data.in > my.out");
        system("std.exe < data.in > std.out");
    } while (!system("fc std.out my.out"));
    printf("Case #%d ERROR.Please check it.\n", cnt);
    system("pause");
    return 0;
}