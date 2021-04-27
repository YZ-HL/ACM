#include <bits/stdc++.h>
#define maxn 105
using namespace std;
int t, n, m;
struct Node{
    int n;
    int m;
    int val;
};
bool operator < (const Node &A, const Node &B){
    return A.val < B.val;
}
vector<Node> v1;
vector<int> out[maxn];
vector<int> ans[maxn];
int used[maxn][maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        v1.clear();
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= max(n, m); i++)    
        {
            out[i].clear();
            ans[i].clear();
        }
        memset(used, 0, sizeof(used));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                v1.push_back((Node){i, j, tmp});
                out[i].push_back(tmp);
            }
        }
        sort(v1.begin(), v1.end());
        for(int i = 1, j = 0; i <= m; i++, j++)
        {
            used[v1[j].n][v1[j].m] = i;
            //printf("debug: %d %d\n", v1[j].n, v1[j].m);
        }
        for(int k = 1; k <= m; k++)
        {
            for(int i = 1; i <= n; i++)
            {
                int flag = -1;
                for(int j = 0; j < out[i].size(); j++)
                {
                    if(used[i][j + 1] == k)
                    {
                        flag = j;
                        break;
                    }
                }
                if(flag != -1)
                {
                    ans[k].push_back(out[i][flag]);
                    //printf("debug: %d %d %d\n", i, out[i][flag], flag);
                }
                else
                {
                    for(int j = 0; j < out[i].size(); j++)
                    {
                        if(used[i][j + 1] == 0)
                        {
                            flag = j;
                            used[i][j + 1] = k;
                            break;
                        }
                    }
                    ans[k].push_back(out[i][flag]);
                }
            }
        }
        //printf("------------\n");
        for(int j = 0; j < n; j++)
            for(int i = 1; i <= m; i++)
                printf(i == m ? "%d\n" : "%d ", ans[i][j]);
    }  
    return 0;
}
