#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#define maxn 100005
using namespace std;
int n, a[maxn], minn = (1<<30), randomcnt = 0;
namespace solve1{
    int num[maxn], liv;
    void inits(){
        liv = n;
        for(int i = 1; i <= n; i++)    num[i] = n;
    }
    void dfs(int x, int dep){
        if(num[x] > 9)
            return;
        int cnt = 0;
        int used[10];
        memset(used, 0, sizeof(used));
        while(1)
        {
            minn = min(minn, liv);
            printf("%d %d\n", liv, minn);
            for(int i = 1; i <= n; i++)    printf("%d ", num[i]);
            putchar('\n');
            //system("pause");
            srand(time(NULL));
            int now = rand() % n + 1;
            if(used[now] || now == x || num[now] <= 0)    continue;
            used[now] = 1;
            cnt++;
            if(cnt == min(a[x], liv - 1))    break;
        }
        for(int i = 1; i <= n; i++)
            if(used[i])
            {
                num[i]--;
                num[x]++;
                if(num[i] == 0)    liv--;
            }
        
        dfs(x == n ? 1 : x + 1, dep+1);

        for(int i = 1; i <= n; i++)
            if(used[i])
            {
                if(num[i] == 0)    liv++;
                num[i]++;
                num[x]--;
            }
    }
}
int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    solve1::inits();
    solve1::dfs(1, 0);
    printf("%d\n", minn);
    /*
    if(n <= 2)
    {
        printf("%d\n", n);
        return 0;
    }
    else if(n == 3)
    {
        if(a[1] >= 2 && a[2] >= 2 && a[3] >= 2)
            printf("%d\n", 3);
        else
            printf("%d\n", 2);
    }
    else
    {
         
    }
    */
    system("pause");
    return 0;
}

