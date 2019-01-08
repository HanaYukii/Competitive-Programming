#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m){
		if(m==1){
			cout<<(ll)n*(ll)(n+1)/2<<endl;
			exit(0);
		}
		else{
			int pre[maxn],cur[maxn];
			f(n){
				cin>>pre[i];
			}
			int cnt[maxn]={};
			cnt[0]=n;
			f(m-1){
				int pos[maxn]={};
				fr(j,0,n){
					cin>>cur[j];
					pos[cur[j]]=j;
				}
				int tcnt[maxn]={};
				fr(j,0,n){
					if(cnt[j]){
						int now=0,p2=0,st;
						for(int k=j;k<j+cnt[j];k++){
							//cout<<pre[k]<<' '<<cur[p2]<<' '<<p2<<endl;
							if(now==0){
								p2=pos[pre[k]]+1;
								st=k;
								now=1;
							}
							else if(pre[k]==cur[p2]){
								now++;
								p2++;
							}
							else{
								tcnt[st]=now;
								st=k;
								p2=pos[pre[k]]+1;
								now=1;
								//cout<<k<<' '<<p2<<endl;
							}
							//cout<<now<<endl;
						}
						tcnt[st]=now;
					}
				}
				fr(j,0,n){
					cnt[j]=tcnt[j];
				}
			}
			ll sum=0;
			f(n){
				sum+=(ll)cnt[i]*((ll)cnt[i]+1)/2;
			}
			cout<<sum<<endl;
		}

	}
}	
