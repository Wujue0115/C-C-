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

    int t,m,n;
    string a,b;
    int dp[91][91];
    vector<int> paths[91][91];

    cin >> t;
    while( t-- ){
        cin >> m >> n;
        
        for( int i=65 ; i<=90 ; ++i ){
            fill(dp[i]+65,dp[i]+91,26);
            dp[i][i]=0;

            for( int j=65 ; j<=90 ; ++j ){
                paths[i][j].clear();
                paths[i][j].emplace_back(i);
                if( i!=j ) paths[i][j].emplace_back(j);
            }
        }
        while( m-- ){
            cin >> a >> b;

            dp[a[0]][b[0]]=dp[b[0]][a[0]]=1;
        }

        for( int k=65 ; k<=90 ; ++k ){
            for( int i=65 ; i<=90 ; ++i ){
                for( int j=65 ; j<=90 ; ++j ){
                    if( dp[i][k]+dp[k][j]<dp[i][j] ){
                        dp[i][j]=dp[i][k]+dp[k][j];

                        paths[i][j]=paths[i][k];
                        if( k!=j ){
                            paths[i][j].insert(paths[i][j].end(),paths[k][j].begin()+1,paths[k][j].end());
                        }
                    }
                }
            }
        }

        while( n-- ){
            cin >> a >> b;

            for( const auto &p:paths[a[0]][b[0]] ){
                cout << char(p);
            }
            cout << '\n';
        }
        if( t ) cout << '\n';
    }
}