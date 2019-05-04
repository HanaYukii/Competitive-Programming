#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
template <typename T>
void karatsuba(int n, T* A, T* B, T* R){ // n = (1<<k)
    memset(R, 0, sizeof(T) * 2 * n);
    if (n <= 16) {
        for (int i =0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                R[i + j] += A[i] * B[j];
        return ;
    }
    int m = n >> 1; 
    karatsuba(m, A, B, R);
    karatsuba(m, A + m, B + m, R + n);
    T* a = new T[m], *b = new T[m], *r = new T[n];
    for (int i = 0 ; i < m ; i++) a[i] = A[i] + A[i + m], b[i] = B[i] + B[i + m];
    karatsuba(m, a, b, r);
    for (int i = 0 ; i < n ; i++) r[i] -= R[i], r[i] -= R[i + n];
    for (int i = 0 ; i < n ; i++) R[i + m] += r[i];
    delete [] a; delete [] b; delete [] r;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >>m >> q;
        ll a[1<<16]={1},b[1<<16]={1},ret[1<<17]={};
        f(n){
            int add;
            cin >> add;
            a[add]++;
        }
        f(m){
            int add;
            cin >> add;
            b[add]++;
        }
        karatsuba(1<<16,a,b,ret);
        while(q--){
            int k;
            cin >>k;
            if(k<=100000)cout<<ret[k]<<'\n';
            else cout<<0<<'\n';
        }
        
}