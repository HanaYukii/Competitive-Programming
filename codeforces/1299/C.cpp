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
struct s{
    ll sum;
    int len;
    double avg;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<s>st;
    f(n){
        int add;
        cin >> add;
        s cur{add,1,add};
        st.push_back(cur);
        while(st.size() >= 2 && st.back().avg < st[st.size()-2].avg){
            cur.len = st.back().len + st[st.size()-2].len;
            cur.sum = st.back().sum + st[st.size()-2].sum;
            cur.avg = (double)cur.sum/(double)cur.len;
            st.pop_back();
            st.pop_back();
            st.push_back(cur);
        }
    }
    cout << fixed << setprecision(12);
    for(auto i:st){
        for(int j = 0 ; j < i.len ; j++){
            cout << i.avg <<'\n';
        }
    }
    cout << '\n';
}
