#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#define FOR(k, x, y) for(int k = x; k <= y; k++)
using namespace std;
int len;
string str;
stack<int> s1;
void solve(){
    int flag = 1;
    FOR(a, 0, 1) FOR(b, 0, 1) FOR(c, 0, 1) FOR(d, 0, 1) FOR(e, 0, 1)
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if(str[i] == 'N')
            {
                int p1 = s1.top();
                s1.pop();
                s1.push(p1 ^ 1);
            }
            else if(str[i] == 'K')
            {
                int p1 = s1.top();
                s1.pop();
                int p2 = s1.top();
                s1.pop();
                (p1 && p2) ? s1.push(1) : s1.push(0);
            }
            else if(str[i] == 'A')
            {
                int p1 = s1.top();
                s1.pop();
                int p2 = s1.top();
                s1.pop();
                (p1 || p2) ? s1.push(1) : s1.push(0);
            }
            else if(str[i] == 'C')
            {
                int p1 = s1.top();
                s1.pop();
                int p2 = s1.top();
                s1.pop();
                (p1 && (!p2)) ? s1.push(0) : s1.push(1);
            }
            else if(str[i] == 'E')
            {
                int p1 = s1.top();
                s1.pop();
                int p2 = s1.top();
                s1.pop();
                (p1 == p2) ? s1.push(1) : s1.push(0);
            }
            else if(str[i] == 'p')
            {
                s1.push(a);
            }
            else if(str[i] == 'q')
            {
                s1.push(b);
            }
            else if(str[i] == 'r')
            {
                s1.push(c);
            }
            else if(str[i] == 's')
            {
                s1.push(d);
            }
            else if(str[i] == 't')
            {
                s1.push(e);
            }
        }
        if(!s1.top())
            flag = 0;
    }
    printf(flag ? "tautology\n" : "not\n");
}
int main(void)
{
    while(cin >> str)
    {
        if(str == "0")
            break;
        len = str.length();
        solve();
    }
    system("pause");
    return 0;
}