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

    const int Mod=1000;
    ll t,n,k;
    double L;
    ll T,n1;

    cin >> t;
    while( t-- ){
        cin >> n >> k;

        L=k*log10(n);
        L=int(pow(10,L-int(L))*100);
 
        T=1; n1=n%Mod;
        while( k ){
            if( k&1 ) T*=n1;
            T%=Mod;
            n1*=n1; n1%=Mod;
            k>>=1;
        }

        cout << setw(3) << setfill('0') << L << "..." << setw(3) << setfill('0') << T%Mod << '\n';
    }
}