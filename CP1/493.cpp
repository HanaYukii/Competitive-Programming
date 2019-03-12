#include<bits/stdc++.h>
int main(){int n;unsigned long long k;std::cin>>n;int a=0;while(n--){int t=0;std::cin>>k;while(k){k>>=1;t++;}a^=t;}if(!a)puts("win");else puts("lose");}
