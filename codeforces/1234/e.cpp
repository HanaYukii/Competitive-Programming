#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7;
 
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<int>pos[n+5];
    ll v[m+5] = {};
    ll val[n+5] = {};
    f1(m){
        cin >> v[i];
        pos[v[i]].pb(i);
    }
    f1(n){
        val[i] = i;
    }
    ll sum = 0;
    f1(m-1){
        sum += abs(v[i]-v[i+1]);
    }
    cout << sum <<' ';
    fr(i,2,n+1){
        int pos1 = i;
        int pos2 = i-1;
        for(auto j:pos[pos1]){
            if(j>1){
                sum -= abs(val[v[j]]-val[v[j-1]]);
            }
            if(j<m){
                sum -= abs(val[v[j]]-val[v[j+1]]);
            }
        }
        for(auto j:pos[pos2]){
            if(j>1&&v[j-1]!=i){
                sum -= abs(val[v[j]]-val[v[j-1]]);
            }
            if(j<m&&v[j+1]!=i){
                sum -= abs(val[v[j]]-val[v[j+1]]);
            }
        }
        swap(val[i],val[i-1]);
        for(auto j:pos[pos1]){
            if(j>1){
                sum += abs(val[v[j]]-val[v[j-1]]);
            }
            if(j<m){
                sum += abs(val[v[j]]-val[v[j+1]]);
            }
        }
        for(auto j:pos[pos2]){
            if(j>1&&v[j-1]!=i){
                sum += abs(val[v[j]]-val[v[j-1]]);
            }
            if(j<m&&v[j+1]!=i){
                sum += abs(val[v[j]]-val[v[j+1]]);
            }
        }
        cout << sum <<' ';
    }
    cout << endl;
}