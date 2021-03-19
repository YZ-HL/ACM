#include <bits/stdc++.h>
using namespace std;
int n, q;
string tmp;
map<string, int> s1;
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        s1[tmp]++;
    }
    scanf("%d", &q);
    while(q--)
    {
        cin >> tmp;
        string r = tmp;
        swap(tmp[0], tmp[1]);
        printf("%d\n", tmp != r ? s1[tmp] + s1[r] : s1[tmp]);
        /*
        if(s1.count(tmp) && s1.count(r))
        {
            printf("%d\n", );
            continue;
        }
        else if(s1.count(tmp) || s1.count(r))
        {
            printf("1\n");
            continue;
        }
        else
            printf("0\n");
        */
    }
    return 0;
}