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
        string s1,s2;
        string s11,s12,s21,s22;
        cin >> n >> s1 >> s2;
        s11 = s1;
        s21 = s2;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        if(s1!=s2){
            cout<<"NO"<<'\n';
            continue;
        }

        int f = 0;
        for(int i=1;i<n;i++){
            if(s1[i]==s1[i-1]){
                f = 1;
            }
        }
        s1 = s11;
        s2 = s21;
        if(f){
            cout<<"YES"<<'\n';
            continue;
        }
        int pos[26]={};
        f(n){
            pos[s1[i]-'a'] = i;
        }
        int inv = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(pos[s2[i]-'a']>pos[s2[j]-'a'])
                {
                    inv++;
                }
            }
        }
        if(inv&1){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
    }
}
