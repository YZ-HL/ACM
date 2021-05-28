#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, t, k;
int main(void)
{
    cin >> n >> t >> k;
    int lf = 1, rt = n, ans = -1;
    while(lf <= rt)
    {
        int mid = (lf + rt) / 2;
        cout << "? " << 1 << " " << mid << endl;
        int val; cin >> val;
        if(mid - val >= k)
            ans = mid, rt = mid - 1;
        else
            lf = mid + 1;
    }
    cout << "! " << ans << endl;
    return 0;
}
