#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
struct s{
    string str;
    int idx;
    int kind;
}cont[5000];
int n;
bool cmp(s x,s y){
    return x.str.size()<y.str.size();
}
bool cmp2(s x,s y){
    return x.idx<y.idx;
}
int test(string s1){
    int l=0,r=n-1;
    int f=0;
    while(l<r){
        if(l+1==r){
            if(cont[l].str+cont[r].str==s1){
                cont[l].kind=1;
                cont[r].kind=2;
            }
            else if(cont[r].str+cont[l].str==s1){
                cont[l].kind=2;
                cont[r].kind=1;
            }
            else{
                f=1;
                break;
            }
        }
        else{
            if(cont[l].str+cont[r].str==s1&&cont[r-1].str+cont[l+1].str==s1){
                cont[l].kind=1;
                cont[l+1].kind=2;
                cont[r].kind=2;
                cont[r-1].kind=1;
            }
            else if(cont[l].str+cont[r-1].str==s1&&cont[r].str+cont[l+1].str==s1){
                cont[l].kind=1;
                cont[l+1].kind=2;
                cont[r].kind=1;
                cont[r-1].kind=2;
            }
            else if(cont[l+1].str+cont[r].str==s1&&cont[r-1].str+cont[l].str==s1){
                cont[l].kind=2;
                cont[l+1].kind=1;
                cont[r].kind=2;
                cont[r-1].kind=1;
            }
            else if(cont[l+1].str+cont[r-1].str==s1&&cont[r].str+cont[l].str==s1){
                cont[l].kind=2;
                cont[l+1].kind=1;
                cont[r].kind=1;
                cont[r-1].kind=2;
            }
            else{
                f=1;
                break;
            }
        }
        l+=2;r-=2;
    }
    return !f;
}
int main(){
    ios::sync_with_stdio(0);
    while(cin>>n){
    
    n=n*2-2;
    f(n){
        cin>>cont[i].str;
        cont[i].idx=i;
    }
    if(n==2){
        cout<<"PS"<<endl;
        continue;
    }
    sort(cont,cont+n,cmp);
    string s1,s2,s3,s4;
    s1=cont[0].str+cont[n-1].str;
    s2=cont[0].str+cont[n-2].str;
    s3=cont[n-1].str+cont[0].str;
    s4=cont[n-2].str+cont[0].str;
    if(test(s1)){
        sort(cont,cont+n,cmp2);
        for(int i=0;i<n;i++){
            if(cont[i].kind==2){
                cout<<"S";
            }
            else{
                cout<<"P";
            }
        }
    }
    else if(test(s2)){
        sort(cont,cont+n,cmp2);
        for(int i=0;i<n;i++){
            if(cont[i].kind==2){
                cout<<"S";
            }
            else{
                cout<<"P";
            }
        }
    }
    else if(test(s3)){
        sort(cont,cont+n,cmp2);
        for(int i=0;i<n;i++){
            if(cont[i].kind==2){
                cout<<"S";
            }
            else{
                cout<<"P";
            }
        }
    }
    else if(test(s4)){
        sort(cont,cont+n,cmp2);
        for(int i=0;i<n;i++){
            if(cont[i].kind==2){
                cout<<"S";
            }
            else{
                cout<<"P";
            }
        }
    }
    cout<<endl;
}
}