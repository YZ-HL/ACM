#include <bits/stdc++.h>
using namespace std;
int t;
string str1, str2;
struct tim{
    int h;
    int m;
    int s;
}s1, t1, s2, t2;
int calc_s(tim now){
    return now.h * 3600 + now.m * 60 + now.s;
}
int fh(int rs){
    return rs / 3600;
}
int fm(int rs){
    return rs / 60 % 60;
}
int fs(int rs){
    return rs % 60;
}
int main(void)
{
    scanf("%d", &t); 
    while(getchar() != '\n');
    while(t--)
    {

        getline(cin, str1);
        getline(cin, str2);
        
        s1.h = (str1[0] - '0') * 10 + (str1[1] - '0');
        s1.m = (str1[3] - '0') * 10 + (str1[4] - '0');
        s1.s = (str1[6] - '0') * 10 + (str1[7] - '0');
        
        t1.h = (str1[9] - '0') * 10 + (str1[10] - '0');
        t1.m = (str1[12] - '0') * 10 + (str1[13] - '0');
        t1.s = (str1[15] - '0') * 10 + (str1[16] - '0');

        if(str1.find("(") != string::npos)    t1.h += (str1[20] - '0') * 24;
        
        s2.h = (str2[0] - '0') * 10 + (str2[1] - '0');
        s2.m = (str2[3] - '0') * 10 + (str2[4] - '0');
        s2.s = (str2[6] - '0') * 10 + (str2[7] - '0');
        
        t2.h = (str2[9] - '0') * 10 + (str2[10] - '0');
        t2.m = (str2[12] - '0') * 10 + (str2[13] - '0');
        t2.s = (str2[15] - '0') * 10 + (str2[16] - '0');

        if(str2.find("(") != string::npos)    t2.h += (str2[20] - '0') * 24;

        /*
        printf("%d %d %d\n", s1.h, s1.m, s1.s);
        printf("%d %d %d\n", t1.h, t1.m, t1.s);
        printf("%d %d %d\n", s2.h, s2.m, s2.s);
        printf("%d %d %d\n", t2.h, t2.m, t2.s);
        */

        int rs = (calc_s(t1) + calc_s(t2) - calc_s(s1) - calc_s(s2)) / 2;
        printf("%02d:%02d:%02d\n", fh(rs), fm(rs), fs(rs));
    }
    return 0;
}