#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod =1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        set<int>st;
        f(k){
            int add;
            cin >> add;
            st.insert(add);
        }
        int pos = n;
        int cnt = 0;
        while(st.lower_bound(pos)!=st.begin()){
            int nxt = *(--st.lower_bound(pos));
            if(nxt <= 1)break;
            if(st.count(nxt-1)){
                pos = nxt - 1;
            }
            else{
                cnt++;
                pos = nxt - 1;
            }
            
        }
        cout << cnt << '\n';
    }
}