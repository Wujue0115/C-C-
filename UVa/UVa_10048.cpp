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

    int times=0,c,s,q,c1,c2,d;
    ll dp[101][101];

    while( cin >> c >> s >> q && c|s|q ){
        for( int i=1 ; i<=c ; ++i ){
            fill(dp[i]+1,dp[i]+c+1,INT_MAX);
            dp[i][i]=0;
        }
        while( s-- ){
            cin >> c1 >> c2 >> d;

            dp[c1][c2]=dp[c2][c1]=d;
        }

        for( int k=1 ; k<=c ; ++k ){
            for( int i=1 ; i<=c ; ++i ){
                for( int j=1 ; j<=c ; ++j ){
                    dp[i][j]=min(dp[i][j],max(dp[i][k],dp[k][j]));
                }
            }
        }

        if( times++ ) cout << '\n';
        cout << "Case #" << times << '\n';

        while( q-- ){
            cin >> c1 >> c2;

            if( dp[c1][c2]!=INT_MAX ){
                cout << dp[c1][c2] << '\n';
            }
            else{
                cout << "no path\n";
            }
        }
    }
}