#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/extc++.h>
using namespace std;
#define io ios::sync_with_stdio(0); cin.tie(0);
#define Filex
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    io;
    #ifdef File
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    ll b,p,m;
    ll ans,b1;

    while( cin >> b >> p >> m ){
        ans=1; b%=m; b1=b;
        while( p ){
            if( p&1 ) ans*=b1;
            b1*=b1; b1%=m;
            p>>=1;
            ans%=m;
        }

        cout << ans << '\n';
    }