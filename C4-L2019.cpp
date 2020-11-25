#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#define maxn 100005
using namespace std;
int n, m, cnt, sum;
set<string> s1;
struct User{
    string name;
    int num;
} U[maxn];
bool cmp(const User &A, const User &B){
    return A.name < B.name;
}
int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        s1.insert(tmp);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int number; string nowuser;
        cin >> nowuser >> number;
        if(!s1.count(nowuser))
        {
            cnt++;
            U[cnt].name = nowuser;
            U[cnt].num = number;
        }
        sum += number;
    }
    int flag = 0;
    double avg = 1.0 * sum / m;
    sort(U+1, U+cnt+1, cmp);
    for(int i = 1; i <= cnt; i++)
    {
        if(U[i].num < avg)    continue;
        cout << U[i].name << endl;
        flag = 1;
    }
    if(!flag)
        cout << "Bing Mei You" << endl;
    return 0;
}
