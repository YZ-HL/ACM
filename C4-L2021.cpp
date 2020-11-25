#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1005
using namespace std;
int n, k;
bool vis[maxn*maxn*10];
struct User{
    string name;
    int diff;
    double avg;
} U[maxn];
bool cmp(const User &A, const User &B){
    if(A.diff != B.diff)
        return A.diff > B.diff;
    return A.avg > B.avg;
}
int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> U[i].name >> k;
        memset(vis, false, sizeof(vis));
        int cnt = 0;
        for(int j = 1; j <= k; j++)
        {
            int tmp;
            cin >> tmp;
            if(!vis[tmp])
                vis[tmp] = true, cnt++;
        }
        U[i].diff = cnt;
        U[i].avg = 1.0 * cnt / k;
    }
    sort(U+1, U+n+1, cmp);
    if(n == 1)
        cout << U[1].name << " - -" << endl;
    else if(n == 2)
        cout << U[1].name << " " << U[2].name << " -" << endl;
    else
        cout << U[1].name << " " << U[2].name << " " << U[3].name << endl;
    return 0;
}
