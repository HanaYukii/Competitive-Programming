#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n,K;
    cin >> n >> K >> s;
    if(count(s.begin(),s.end(),'B')==n||count(s.begin(),s.end(),'W')==n){
        cout << s << endl;
        return 0;
    }
    bool dif = 1;
    f(n){
        if(s[i]==s[(i+1)%n]){
            dif = 0;
        }
    }
    if(dif){
        if(K%2){
            cout << s.substr(1) << s[0] << endl;
        }
        else{
            cout << s << endl;
        }
        return 0 ;
    }
    s = s+s+s;
    vector<bool>one(3*n,false);
    f(3*n){
        one[i] = i > 0 && i < 3 * n - 1 && s[i] != s[i-1] && s[i] !=s[i+1];
    }
    for(int i=0,j=0;i<3*n;i=j){
        if(!one[i]){
            j = i + 1;
            continue;
        }
        while(j < 3 * n && one[j]){
            j++;
        }
        int count  = j - i;
        for(int k = 0 ; k < count ; k++){
            if(K>=min(k+1,count-k))
                s[i+k] = k < count / 2 ? s[i-1] : s[j];
            else{
                s[i+k] = (K % 2 == 0 ? s[i+k] : 'B' + 'W' - s[i+k]);
            }
        }
    }
    cout << s.substr(n,n) << endl;
}