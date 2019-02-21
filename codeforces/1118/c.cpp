#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int main(){
	int n;
    while(cin>>n){
    	map<int,int>mp;
        int board[n+5][n+5]={};
        f1(n*n){
            int add;
            cin>>add;
            mp[add]++;
        }
        if(n==1){
            cout<<"YES"<<endl;
            auto it=*(mp.begin());
            cout<<it.first<<endl;
            exit(0);
        }
        //int sig=0,db=0;
        vector<int>sig;
        vector<int>db;
        vector<int>four;
        for (auto i:mp){
            if(i.second&1){
                sig.pb(i.first);
                mp[i.first]--;
            }
            if(i.second%4==2){
                db.pb(i.first);
                mp[i.first]-=2;
            }
            for(int j=0;j<i.second/4;j++){
                four.pb(i.first);
            }
            
        }
        //cout<<endl;
        //cout<<four[0]<<' '<<four[1]<<endl;
        if(n%2==0){
            if(sig.size()||db.size()){
                cout<<"NO"<<endl;
            }
            else{
                int now=0;
                cout<<"YES"<<endl;
                f1(n/2){
                    fr(j,1,n/2+1){
                        int z=four[now++];
                        board[i][j]=z;
                        board[i][n+1-j]=z;
                        board[n+1-i][j]=z;
                        board[n+1-i][n+1-j]=z;
                    }
                }
                f1(n){
                    fr(j,1,n+1){
                        cout<<board[i][j]<<' ';
                    }
                    cout<<endl;
                }
            }
        }
        else{
            if(sig.size()!=1||(int)db.size()>n/2*2||(int)db.size()&1){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
                board[n/2+1][n/2+1]=sig[0];
                int cnt=1;
                //cout<<"gg"<<endl;
                for(auto i:db){
                    if(cnt<=n/2){
                        board[cnt][n/2+1]=i;
                        board[n+1-cnt][n/2+1]=i;
                    }
                    else{
                        board[n/2+1][cnt-n/2]=i;
                        board[n/2+1][n+1-(cnt-n/2)]=i;
                    }
                    cnt++;
                }
                //cout<<"gg"<<endl;
                int now=0;
                for(int i=cnt;i<n-1;i+=2){
                    int k=four[now++];
                    //cout<<k<<' '<<cnt<<endl;
                    if(cnt<=n/2){
                        board[cnt][n/2+1]=k;
                        board[n+1-cnt][n/2+1]=k;
                        //cnt++;
                    }
                    else{
                        board[n/2+1][cnt-n/2]=k;
                        board[n/2+1][n+1-(cnt-n/2)]=k;
                        //cnt++;
                    }
                    cnt++;
                    if(cnt<=n/2){
                        board[cnt][n/2+1]=k;
                        board[n+1-cnt][n/2+1]=k;
                    }
                    else{
                        board[n/2+1][cnt-n/2]=k;
                        board[n/2+1][n+1-(cnt-n/2)]=k;
                        
                    }
                    cnt++;
                }
                //cout<<"gg"<<endl;
                f1(n/2){
                    fr(j,1,n/2+1){
                        int z=four[now++];
                        board[i][j]=z;
                        board[i][n+1-j]=z;
                        board[n+1-i][j]=z;
                        board[n+1-i][n+1-j]=z;
                    }
                }
                //cout<<"gg"<<endl;
                f1(n){
                    fr(j,1,n+1){
                        cout<<board[i][j]<<' ';
                    }
                    cout<<endl;
                }
                
            }
        }
    }
}