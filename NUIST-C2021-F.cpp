#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
int n, k, a[maxn];
struct Node{
    int pos;
    int dis;
}N[maxn];
bool operator < (const Node &A, const Node &B){
    return A.dis != B.dis ? A.dis > B.dis : A.pos < B.pos;
}
int c[maxn];
int lowbit(int k){
    return k & (-k);
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}
void update(int x, int k){
    for(int i = x; i <= n; i += lowbit(i))
        c[i] += k;
}
int main(void)
{
    scanf("%d %d", &n, &k);
    int bas = 1, np = -1;
    priority_queue<Node> q1;
    for(int i = 1; i <= n; i++)
    {
        if(bas == i)    np = i, bas *= 2;
        scanf("%d", &a[i]);
        if(a[i] == k)
            q1.push((Node){i, i - np});
    }
    int cnt = 0;
    while(!q1.empty())
    {
        Node tmp = q1.top();
        //printf("debug3: %d %d\n", tmp.dis, tmp.pos);
        while(tmp.dis - query(tmp.pos) <= 0)
        {
            update(tmp.pos, 1);
            q1.pop();
            cnt++;
            //printf("debug1: %d\n", cnt);
            if(q1.empty())    break;
            tmp = q1.top();
        }
        if(!q1.empty() && tmp.dis - query(tmp.pos) > 0)
        {
            //printf("debug4: %d %d %d\n", tmp.dis, tmp.pos, tmp.dis - query(tmp.pos));
            cnt += tmp.dis - query(tmp.pos) + 1;
            update(tmp.pos - tmp.dis, tmp.dis - query(tmp.pos) + 1);
            q1.pop();
            //printf("debug2: %d\n", cnt);
        }
    }
    printf("%d\n", cnt);
    return 0;
}