#include<bits/stdc++.h>
using namespace std;

int  main(){
    int k,t;
    cin>>t;
    while(t--){
    string s;
    int f=0;
    cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            f=1;
        }
    }
    if(!f){
        cout<<-1<<endl;
    }
    else{
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
}
}