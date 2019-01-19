#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios_base::sync_with_stdio(0);
    string s;
    int n,m;
    while(cin>>s){
        stack<ll>st;
        vector<int>op;
        vector<ll>num;
        ll tmp=0;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='+'){
                op.pb(1);
                num.pb(tmp);
                tmp=0;
                //cout<<1<<endl;
            }
            else if(s[i]=='*'){
                op.pb(2);
                num.pb(tmp);
                tmp=0;
                //cout<<2<<endl;
            }
            else{
                tmp*=10;
                tmp+=s[i]-'0';
                //cout<<3<<endl;
            }
        }
        //cout<<op.size()<<' '<<num.size()<<endl;
        num.pb(tmp);
        ll ans1=num[0];
        for(int i=0;i<(int)op.size();i++){
            if(op[i]==1){
                ans1+=num[i+1];
            }
            else{
                ans1*=num[i+1];
            }
        }
        st.push(num[0]);
        for(int i=0;i<(int)op.size();i++){
            st.push(num[i+1]);
            if(op[i]==2){
                ll n1=st.top();
                st.pop();
                ll n2=st.top();
                st.pop();
                st.push(n1*n2);
            }
        }
        ll ans2=0;
        while(!st.empty()){
            ans2+=st.top();
            st.pop();
        }
        ll k;
        cin>>k;
        //cout<<ans1<<' '<<ans2<<endl;
        if(ans1==k&&ans2==k){
            cout<<"U"<<endl;
        }
        else if(ans2==k){
            cout<<"M"<<endl;
        }
        else if(ans1==k){
            cout<<"L"<<endl;
        }
        else{
            cout<<"I"<<endl;
        }
    }
    
}