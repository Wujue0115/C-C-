#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/extc++.h>
using namespace std;
#define io ios::sync_with_stdio(0); cin.tie(0);
#define Filex
#define fi first
#define se second

typedef long long ll;

int main(){
    io;
    #ifdef File
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    int times=0,t,sum,counts[3];
    string n;

    cin >> t;
    while( t-- ){
        cin >> n;

        sum=0;
        memset(counts,0,sizeof(counts));
        for( const auto p:n ){
            sum+=p^48;
            ++counts[(p^48)%3];
        }

        cout << "Case " << ++times << ": ";

        if( sum%3 ){
            if( counts[sum%3] ){
                cout << (counts[0]&1 ? "T" : "S" ) << '\n';
            }
            else{
                cout << "T\n";
            }
        }
        else{
            cout << ( counts[0]&1 ? "S" : "T" ) << '\n';
        }
    }
}