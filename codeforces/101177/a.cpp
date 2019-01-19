
 #include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
void p2x(ll p,int &x,int &y){
    if(p==1){
        x=0;y=0;
        return;
    }
    ll sm=(ll)sqrt(p-1);
    if(!(sm&1)){
        sm--;
    }
    //cout<<sm<<endl;
    if(p-sm*sm<=sm+1){
        y=-(int)(sm/2+1);
        x=-(int)(sm/2+1)+(p-(sm*sm));
    }
    else if(p-sm*sm<=(sm+1)*2){
        x=(int)(sm/2+1);
        y=-(int)(sm/2+1)+(p-(sm*sm)-(sm+1));
    }
    else if(p-sm*sm<=(sm+1)*3){
        y=(int)(sm/2+1);
        x=(int)(sm/2+1)-(p-(sm*sm)-((sm+1)*2));
    }
    else{
        x=-(int)(sm/2+1);
        y=(int)(sm/2+1)-(p-(sm*sm)-((sm+1)*3));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    ll n,m;
    while(cin>>n>>m){
        int x,y,x2,y2;
        p2x(n,x,y);
        p2x(m,x2,y2);
        //cout<<x<<' '<<y<<' '<<x2<<' '<<y2<<endl;
        cout<<abs(x-x2)+abs(y-y2)<<endl;
    }

}