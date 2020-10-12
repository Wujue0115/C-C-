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

    int times=0,n,x,a,b;
    int dp[21][21];

    while( cin >> n ){
        for( int i=1 ; i<=20 ; ++i ){
            fill(dp[i]+1,dp[i]+21,20);
            dp[i][i]=0;
        }
        while( n-- ){
            cin >> x;

            dp[1][x]=dp[x][1]=1;
        }

        for( int i=2 ; i<=19 ; ++i ){
            cin >> n;

            while( n-- ){
                cin >> x;

                dp[i][x]=dp[x][i]=1;
            }
        }

        for( int k=1 ; k<=20 ; ++k ){
            for( int i=0 ; i<=20 ; ++i ){
                for( int j=1 ; j<=20 ; ++j ){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        cout << "Test Set #" << ++times << '\n';

        cin >> n;
        while( n-- ){
            cin >> a >> b;

            cout << setw(2) << a << " to " << setw(2) << b << ": " << dp[a][b] << '\n';
        }
        cout << '\n';
    }
}