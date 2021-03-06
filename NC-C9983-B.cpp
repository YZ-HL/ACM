#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
using namespace std;
int n, k, ans = (1 << 30), ed[maxn];
int num_p, num_a, user[maxn], hava[maxn], inq[maxn];
struct val{
    int p;
    int sc;
    bool isa;
}v[maxn];
bool cmp(const val &A, const val &B){
    if(A.sc == B.sc)
        return A.p == B.p ? A.isa < B.isa : A.p < B.p; 
    return A.sc < B.sc;
}
int main(void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        v[i].p = i; v[i].sc = a; v[i].isa = true;
        v[i + n].p = i; v[i + n].sc = b; v[i + n].isa = false;
        v[i + 2 * n].p = i; v[i + 2 * n].sc = c; v[i + 2 * n].isa = false;
        v[i + 3 * n].p = i; v[i + 3 * n].sc = d; v[i + 3 * n].isa = false;
        v[i + 4 * n].p = i; v[i + 4 * n].sc = e; v[i + 4 * n].isa = false;
    }
    sort(v + 1, v + 5 * n + 1, cmp);
    ed[0] = 1;
    for(int i = 1; i <= 5 * n; i++)
    {
        if(ed[i - 1] == -1)    break;
        for(int j = ed[i - 1]; j <= 5 * n; j++)
        {
            if(!inq[j])
            {
                inq[j] = 1;
                if(user[v[j].p] == 0 && hava[v[j].p] == 0)
                {
                    num_p++;
                    if(v[j].isa)
                    {
                        hava[v[j].p] = 1;
                        num_a++;
                    }
                    else
                        user[v[j].p]++;
                }
                else
                {
                    if(v[j].isa)
                        hava[v[j].p] = 1;
                    else
                    {
                        //if(hava[v[j].p])    num_a--;
                        user[v[j].p]++;
                    }
                }
            }
            if(num_a > k)
            {
                ed[i] = j;
                break;
            }
            if(num_p == n)
            {
                ans = min(ans, v[j].sc - v[i].sc);
                //printf("%d %d %d\n", i, j, ans);
                ed[i] = j;
                break;
            }
            if(j == 5 * n)    ed[i] = -1;
        }
        if(v[i].isa)
        {
            hava[v[i].p] = 0;
            if(user[v[i].p] == 0)    num_p--;
        }
        else
        {
            user[v[i].p]--;
            if(hava[v[i].p] && user[v[i].p] == 0)    num_a++;
            else if(user[v[i].p] == 0 && hava[v[i].p] == 0)    num_p--;
        }
    }
    printf("%d\n", ans);
    return 0;
}