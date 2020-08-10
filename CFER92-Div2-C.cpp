#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int count_str1(const string str, const string sub){
	int num = 0, pos = 0;
    int len = str.size();
    for(int i = 0; i <= len-1; i++)
    {
        if((!pos) && str[i] == sub[pos])  pos ^= 1;
        else if(pos && str[i] == sub[pos])   num++, pos ^= 1;
    }
    return num;
}
int count_str2(const string str, const string sub){
    int num = 0;
    int len = str.size();
    for (int i = 0; i <= len - 1; i++)
        if(str[i] == sub[0])
            num++;
    return num;
}
int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        string str; cin >> str;
        int maxx = 0;
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j <= 9; j++)
                maxx = max(maxx, count_str1(str, to_string(i)+to_string(j)));
        int sg_flag = 0, maxx2 = 0;
        for (int i = 0; i <= 9; i++)
            maxx2 = max(maxx2, count_str2(str, to_string(i)));
        if (maxx2 > maxx*2)
            sg_flag = 1, maxx = maxx2;
        if (str.size() == 1)
            printf("0\n");
        else
            printf("%d\n", sg_flag ? str.size() - maxx : str.size() - maxx * 2);
    }
    system("pause");
    return 0;
}
