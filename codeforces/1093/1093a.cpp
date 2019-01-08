#include<bits/stdc++.h>
using namespace std;

int  main(){
    int k,t;
    cin>>t;
    while(t--){
    cin>>k;
    cout<<(k%6?k/6+1:k/6)<<endl;
}
}