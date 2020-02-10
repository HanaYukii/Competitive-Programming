#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
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
    int n;
    cin >> n;
    multiset<string>st1;
    cout << '?' << ' ' << 1 <<' '<< n << endl;
    for(int i = 0 ; i < n * (n + 1)/2 ; i++){
      string s;
      cin >> s;
      sort(s.begin(),s.end());
      st1.insert(s);
    }
    if(n==1){
      cout << '!' << ' '<<*st1.begin() << endl;
      exit(0);
    }
    cout << '?' << ' ' << 2 <<' '<< n << endl;
    for(int i = 0 ; i < (n - 1) * (n)/2 ; i++){
      string s;
      cin >> s;
      sort(s.begin(),s.end());
      st1.erase(st1.lower_bound(s));
    }
    vector<string>v;
    for(auto i:st1){
      v.pb(i);
    }
    sort(v.begin(),v.end(),[](string a,string b){
      return a.size() < b.size();
    });
    string ans = "";
    ans = v[0];
    for(int i = 1 ; i < n ; i++){
      multiset<char>st;
      for(auto j:v[i]){
        st.insert(j);
      }
      for(auto j:v[i-1]){
        st.erase(st.lower_bound(j));
      }
      ans += *st.begin();
    }
    cout << '!' <<' '<<ans << endl;
}
