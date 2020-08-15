#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int s, d, sta[15];
int near5_res, all_res;
void check(int x)
{
    int pos = x;
    while (near5_res >= 0 && pos >= x-4)
    {
        if (!sta[pos])
        {
            sta[pos] = 1;
            near5_res -= (s+d);
        }
        pos--;
    }
}
int main(void)
{
    while (~scanf("%d %d", &s, &d))
    {
        memset(sta, 0, sizeof(sta));
        near5_res = s * 5, all_res = 0;
        for (int i = 5; i <= 12; i++)
        {
            check(i);
            near5_res = 0;
            for (int j = i - 3; j <= i + 1; j++)
                near5_res += (sta[j] ? d * (-1) : s);
        }
        for (int i = 1; i <= 12; i++)
            all_res += (sta[i] ? d * (-1) : s);
        all_res > 0 ? printf("%d\n", all_res) : printf("Deficit\n");
    }
    system("pause");
    return 0;
}