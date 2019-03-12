#include <bits/stdc++.h>
using namespace std;
int main(void){
    int k;
    while(cin>>k){
        string a,b;
        cin>>a>>b;
        bool connect[k][k];
        memset(connect,0,sizeof(connect));
        for(int i= 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(a[i]==b[j]){
                    connect[i][j]=true;
                }
            }
        }
        int last[k];
        for(int i = 0; i < k; i++){
            last[i]=i;
        }
        for(int i= k; i < a.size();i= i +k){
            for(int j = 0; j < k;j ++){
                last[j]=k+j;
                for(int l = 0; l < k; l++){
                    if(connect[j][l]&&a[k+j]!=b[k+l]){
                        connect[j][l]=false;
                    }
                }
            }
        }
        long long int total = 1;
       /*for(int i = 0; i < k; i++){
            for(int j =0 ; j < k; j++){
                cout<<connect[i][j]<<' ';
            }
            cout<<'\n';
        }*/
        //cout<<"why\n";
        int in[k],out[k];
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i = 0; i < k;i++){
            for(int j = 0 ; j < k; j++){
                if(connect[i][j]){
                    in[i]++;
                    out[j]++;
                }
            }
        }
        bool fail = false;
        for(int i = 0; i < k; i++){
            for(int j=0; j < k; j++){
                if(connect[i][j]&&in[i]!=out[j]){
                    fail = true;
                    break;
                }
                if(in[i]==0||out[j]==0){
                    fail = true;
                    break;
                }
            }
            if(fail){
                break;
            }
        }
        if(fail){
            cout<<"0\n";
        }
        else{
            long long int cnt[101];
            memset(cnt,0,sizeof(cnt));
            for(int i = 0; i <k ; i++){
                cnt[in[i]]++;
            }
            for(int i = 1; i<=100;i++){
                cnt[i]=cnt[i]/i;
                //cout<<cnt[i]<<'\n';
            }
            long long int cur = 1;
            for(long long i = 1; i <=100; i++){
                cur = cur *i;
                for(int j = 1; j <= cnt[i];j++){
                    total = total * cur;
                }
            }
            cout<<total<<'\n';
        }
    }
}
