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
#define pii pair<int,int>
int main(){
	int n;
    while(cin>>n){
    	set<pair<int,int> >st;
        int ans[n+5][n+5] = {};
        map<int,int>mp;
        f(n*n){
            int add;
            cin >> add;
            mp[add]++;
        }
        for(auto i:mp){
            st.insert({i.S,i.F});
        }
        if(n%2==0){
            for(int i=1;i<=n/2;i++){
                for(int j=1;j<=n/2;j++){
                    pii cur = *(--(st.end()));
                    st.erase(cur);
                    if(cur.F<4){
                        cout<<"NO"<<endl;
                        exit(0);
                    }
                    ans[i][j]=ans[n+1-i][j]=ans[i][n+1-j]=ans[n+1-i][n+1-j] = cur.S;
                    cur.F -=4;
                    st.insert(cur);
                }
            }
        }
        else{
            for(int i=1;i<=n/2;i++){
                for(int j=1;j<=n/2;j++){
                    pii cur = *(--(st.end()));
                    st.erase(cur);
                    if(cur.F<4){
                        cout<<"NO"<<endl;
                        exit(0);
                    }
                    ans[i][j]=ans[n+1-i][j]=ans[i][n+1-j]=ans[n+1-i][n+1-j] = cur.S;
                    cur.F -=4;
                    st.insert(cur);
                }
            }
            for(int i=1;i<=n/2;i++){
                pii cur = *(--(st.end()));
                st.erase(cur);
                if(cur.F<2){
                    cout<<"NO"<<endl;
                    exit(0);
                }
                ans[i][n/2+1]=ans[n+1-i][n/2+1] = cur.S;
                cur.F -= 2;
                st.insert(cur);
                cur = *(--(st.end()));
                st.erase(cur);
                if(cur.F<2){
                    cout<<"NO"<<endl;
                    exit(0);
                }
                ans[n/2+1][i]=ans[n/2+1][n+1-i] = cur.S;
                cur.F -= 2;
                st.insert(cur);
            }
            pii cur = *(--(st.end()));
            ans[n/2+1][n/2+1] = cur.S;
        }
        cout << "YES" << endl;
        f1(n){
            fr(j,1,n+1){
                cout << ans[i][j]<<' ';
            }
            cout << endl;
        }
    }
}