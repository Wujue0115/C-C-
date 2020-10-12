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

    int n,a,b,m,s;
    bool dp[101][101];
    vector<int> ivec;

    while( cin >> n && n ){
        memset(dp,false,sizeof(dp));
        while( cin >> a && a ){
            while( cin >> b && b ){
                dp[a][b]=true;
            }
        }

        for( int k=1 ; k<=n ; ++k ){
            for( int i=1 ; i<=n ; ++i ){
                for( int j=1 ; j<=n ; ++j ){
                    dp[i][j]=( dp[i][j]|( dp[i][k]&dp[k][j] )) ;
                }
            }
        }

        cin >> m;
        while( m-- ){
            cin >> s;

            ivec.clear();
            for( int i=1 ; i<=n ; ++i ){
                if( !dp[s][i] ){
                    ivec.emplace_back(i);
                }
            }

            cout << ivec.size();
            for( const auto &p:ivec ){
                cout << ' ' << p;
            }
            cout << '\n';
        }
    }
}