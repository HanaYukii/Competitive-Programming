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
const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int f = 0,sum = 0;
        map<int,int>mp;
        for(auto i:s){
            if(i != '0'){
                f = 1;
            }
            mp[i-'0']++;
            sum += i - '0';
        }
        if(!f){
            cout << "red" << '\n';
            continue;
        }
        if(sum % 3 == 0){
            if(!mp.count(0)){
                cout << "cyan" << '\n';
            }
            else{
                if(mp[0]>=2||mp[6]||mp[2]||mp[8]||mp[4]){
                    cout<<"red"<<'\n';
                }
                else{
                    cout << "cyan" << '\n';
                }
            }
        }
        else{
            cout << "cyan" << '\n';
        }
    }
}
