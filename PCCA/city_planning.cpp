#include<bits/stdc++.h>
#include<random>
using namespace std;

int main(){
	srand(time(NULL));
	cout<<10<<endl;
	for(int t=1;t<=10;t++){
		int n;
		if(t<5){
			n=rand()%30;
		}
		else{
			n=100000;
		}
		int k=rand()%(n-1)+1;
		vector<pair<int,int>>edge;
		vector<long long>weight;
		for(int i=2;i<=n;i++){
			int f=i;
			int s=(rand()%(i-1))+1;
			if(rand()&1){
				edge.push_back(make_pair(f,s));
			}
			else{
				edge.push_back(make_pair(s,f));
			}
		}
		for(int i=0;i<k;i++){
			weight.push_back(rand()%k+1);
		}
		default_random_engine defaultEngine;    
		shuffle(edge.begin(), edge.end(), defaultEngine);
		cout<<n<<' '<<k<<endl;
		for(auto i:edge){
			cout<<i.first<<' '<<i.second<<endl;
		}
		for(auto i:weight){
			cout<<i<<' ';
		}
		cout<<endl;
	}
}
