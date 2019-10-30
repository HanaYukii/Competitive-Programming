#include <bits/stdc++.h>
using namespace std ;
 
typedef long long LL ;
 
#define clr( a , x ) memset ( a , x , sizeof a )
 
const int MAXN = 100 ;
 
int x , y , n ;
 
void solve () {
    scanf ( "%d" , &n ) ;
    double v = 0 , f ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int l , r ;
        scanf ( "%d%d%lf" , &l , &r , &f ) ;
        y -= r - l ;
        v += ( r - l ) * f ;
    }
    v += y ;
    printf ( "%.10f\n" , x / v ) ;
}
 
int main () {
    while ( ~scanf ( "%d%d" , &x , &y ) ) solve () ;
    return 0 ;
}
