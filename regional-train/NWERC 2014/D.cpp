#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
int in[maxn];
int d[maxn];
int l[maxn],r[maxn];
ll cnt[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    f1(m){
        char c;
        cin >> c >> l[i] >> r[i];
        in[l[i]]++,in[r[i]]++;
        if(c=='L'){
            d[i] = 1;
        }
    }
    cnt[1] = n;
    queue<int>q;
    f1(m){
        if(!in[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ll num = cnt[now];
        cnt[l[now]] += num / 2;
        cnt[r[now]] += num / 2;
        if(num&1){
            if(d[now]){
                cnt[l[now]]++;
            }
            else{
                cnt[r[now]]++;
            }
        }
        in[l[now]]--;
        if(!in[l[now]]){
            q.push(l[now]);
        }
       
        in[r[now]]--;
        if(!in[r[now]]){
            q.push(r[now]);
        }
        d[now] ^= (num&1);
    }
    f1(m){
        if(d[i]){
            cout<<'L';
        }
        else{
            cout<<'R';
        }
    }
    cout << endl;
}
