#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int cnt = 0;
    do{
        printf("Case #%d:\n", ++cnt);
        system("maker.exe");
        system("POJ1328.exe < data.txt > myout.txt");
        system("POJ1328-FC.exe < data.txt > stdout.txt");
    } while (!system("fc myout.txt stdout.txt"));
    system("pause");
    return 0;
}