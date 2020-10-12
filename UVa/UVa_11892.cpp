#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/extc++.h>
using namespace std;
#define io ios::sync_with_stdio(0); cin.tie(0);
#define Filex
#define fi first
#define se second

typedef long long ll;
typedef pair<int,string> pis;

int main(){
    io;
    #ifdef File
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    int t,n,num,ones;

    cin >> t;
    while( t-- ){
        cin >> n;

        ones=0;
        for( int i=0 ; i<n ; ++i ){
            cin >> num;

            if( num==1 ){
                ++ones;
            }
        }

        cout << ( ones==n ? ( n&1 ? "poopi" : "piloop" ) : "poopi" ) << '\n';
    }
}