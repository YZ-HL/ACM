#include <bits/stdc++.h>
using namespace std;
int week[2005][15][35];
int mday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int calc(int y, int m){
    if(m != 2)  return mday[m];
    return ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
}
int calc2(int y, int m){
    if(m == 12)
        return week[y + 1][1][1] - 1;
    else
        return week[y][m + 1][1] - 1;
}
int main(void)
{
    week[2001][1][1] = 1;
    week[2000][12][31] = 0;
    for(int i = 2000; i >= 1901; i--)
        for(int j = 12; j >= 1; j--)
            for(int k = calc(i, j); k >= 1; k--)
            {
                if(k == calc(i, j))
                    week[i][j][k] = calc2(i, j);
                else
                    week[i][j][k] = week[i][j][k + 1] - 1;
                
                if(week[i][j][k] < 0)
                    week[i][j][k] += 7; 
                
                /*
                if(j == 1 && k == 1)
                    system("pause");

                printf("%d %d %d %d\n", i, j, k, week[i][j][k]);
                
                if(j == 12 && k == 31)
                    system("pause");
                */
            }
    int cnt = 0;
    for(int i = 2000; i >= 1901; i--)
        for(int j = 12; j >= 1; j--)
            for(int k = calc(i, j); k >= 1; k--)
                if(week[i][j][k] == 1)
                    cnt++;
    printf("%d\n", cnt);
    return 0;  
}