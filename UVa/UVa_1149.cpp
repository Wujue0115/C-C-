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

    int t,n,l[100001];
    int left,right;

    cin >> t;
    while( t-- ){
        cin >> n >> l[0];
        for( int i=1 ; i<=n ; ++i ){
            cin >> l[i];
        }

        sort(l+1,l+n+1);

        left=1; right=n; 
        while( left<right ){
            if( l[left]+l[right]<=l[0] ){
                --n;
                ++left; --right;
            }
            else{
                --right;
            }
        }

        cout << n << '\n';
        if( t ) cout << '\n';
    }
}