#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));


int main(){
    ios_base::sync_with_stdio(0);
    int n,m,k;
    while(cin>>n){
        stack<int>st;
        int mx=0;
        f(n){
            int add;
            cin>>add;
            mx=max(mx,add);
            if(st.size()){
                int tp=st.top();
                if(add>tp.top()){
                    cout<<"NO"<<endl;
                    exit(0);
                }
                if((add!=tp)){
                    st.push(add);
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(add);
            }
        }
        if(st.size()==0){
            cout<<"YES"<<endl;
        }
        else if(st.size()==1){
            if(st.top()<mx){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
}