#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
string res[1025][1025];
string reverse_it(string now){
    int len = now.length();
    string resans = "";
    for(int i = 0; i <= len-1; i++)
        resans += (now[i] == 'C' ? 'P' : 'C');
    return resans;
}
string dfs(int k, int x){
    if(!res[k][x].empty())
        return res[k][x];
    if(x > (int)pow(2, k-1))
    {
        string nres = dfs(k-1, x-(int)pow(2, k-1));
        string fres = reverse_it(nres);
        res[k][x] = fres + nres;
    }
    else
    {
        string nres = dfs(k-1, x);
        res[k][x] = nres + nres;
    }
    return res[k][x];
}
int main(void)
{
    res[1][1] = "CC";
    res[1][2] = "PC";

    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int maxl = pow(2, n);
        for(int i = 1; i <= maxl; i++)  
            cout << dfs(n, i) << endl;
    }
    system("pause");
    return 0;
}
