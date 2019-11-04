#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v;
        int ptr = 0;
        f(n){
            int add;
            cin >> add;
            v.pb(add);
        }
        while(ptr<n){
            int mi = v[ptr];
            int idx = ptr;
            for(int i=ptr+1;i<n;i++){
                if(v[i]<mi){
                    mi = v[i];
                    idx = i;
                }
            }
            if(idx == ptr){
                ptr++;
            }
            else{
                for(int i=idx-1;i>=ptr;i--){
                    swap(v[i],v[i+1]);
                }
                ptr = idx;
            }
        }
        f(n){
            cout << v[i] << ' ';
        }
        cout << endl;
    }
}
