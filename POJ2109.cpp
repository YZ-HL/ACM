#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define maxn 1005
using namespace std;
int n, ans;
string p;
int calc[maxn];
string int_to_str(int x)
{
    string tmp = "";
    while (x)
    {
        int tm = x % 10;
        x /= 10;
        tmp = tmp + (char)(tm + '0');
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}
string mul(string a, string b)
{
    memset(calc, 0, sizeof(calc));
    int lena = a.length();
    int lenb = b.length();
    for (int i = lena - 1; i >= 0; i--)
    {
        int numa = a[i] - '0';
        for (int j = lenb - 1; j >= 0; j--)
        {
            int numb = b[j] - '0';
            int cal = numa * numb;
            calc[i + j + 1] += cal;
            if (calc[i + j + 1] >= 10)
            {
                calc[i + j] += calc[i + j + 1] / 10;
                calc[i + j + 1] %= 10;
            }
        }
    }
    string res = "";
    if(calc[0])
        res += (char)(calc[0] + '0');
    for (int i = 1; i <= lena + lenb - 1; i++)
        res += (char)(calc[i] + '0');
    return res;
}
bool cmp_str(string a, string b){
    int lena = a.length();
    int lenb = b.length();
    if(lena > lenb)
        return true;
    if(lena < lenb)
        return false;
    for (int i = 0; i <= lena; i++)
        if(a[i] != b[i])
            return a[i] > b[i];
    return true;
}
bool check(int x)
{
    string tmp = "1";
    string bas = int_to_str(x);
    for (int i = 1; i <= n; i++)
        tmp = mul(tmp, bas);
    //cout << tmp << endl;
    return cmp_str(p, tmp);
}
int main(void)
{
    while(cin >> n >> p)
    {
        int lf = 1, rt = 1e9;
        while (lf <= rt)
        {
            int mid = (lf + rt) / 2;
            check(mid) ? ans = mid, lf = mid + 1 : rt = mid - 1;
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}

//Another way
//由于k被限制在10^9内，double的有效精度足以表示出k
/*
double n, p;
cin >> n >> p;
cout << pow(p, 1/n) << endl;
*/
//对于样例: cout << pow(4357186184021382204544.0, 1.0 / 7) << endl;