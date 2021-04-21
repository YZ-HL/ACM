#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, c[maxn];
int top, flag, s[maxn];
int lowbit(int x){
    return x & (-x);
}
void update(int x, int val){
    while(x <= maxn - 5){
        c[x] += val;
        x += lowbit(x);
    }
}
int getsum(int x){
    int sum = 0;
    while(x){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
int check(int pos){
    int lf = 1, rt = 1e5, ans;
    while(lf <= rt)
    {
        int mid = (lf + rt) / 2;
        getsum(mid) > pos ? ans = mid, rt = mid - 1 : lf = mid + 1;
    }
    return ans;
}
int main(void)
{
    //freopen("tmp.txt", "w", stdout);
    cin >> n;
    while(n--)
    {
        int val; string op;
        cin >> op;
        if(op == "Push")   
        {
            cin >> val;
            update(val, 1);
            s[++top] = val;
        }
        else if(op == "Pop")     
        {
            if(top == 0)
            {
                cout << "Invalid" << '\n';
                continue;
            }
            cout << s[top] << '\n';
            update(s[top--], -1);
        }
        else
        {
            if(top == 0)
            {
                cout << "Invalid" << '\n';
                continue;
            }
            int que = check((top + 1) / 2 - 1);
            cout << que << '\n';
        }
    }
    return 0;
}
