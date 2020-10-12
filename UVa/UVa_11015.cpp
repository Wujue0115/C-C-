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

    int times=0,n,m,a,b,k;
    string names[23],ans;
    int dp[23][23],sum,imin;

    while( cin >> n >> m && n|m ){
        for( int i=1 ; i<=n ; ++i ){
            cin >> names[i];

            fill(dp[i]+1,dp[i]+n+1,22000);
            dp[i][i]=0;
        }

        while( m-- ){
            cin >> a >> b >> k;

            dp[a][b]=dp[b][a]=k;
        }

        for( int k=1 ; k<=n ; ++k ){
            for( int i=1 ; i<=n ; ++i ){
                for( int j=1 ; j<=n ; ++j ){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        imin=INT_MAX;
        for( int i=1 ; i<=n ; ++i ){
            sum=0;

            for( int j=1 ; j<=n ; ++j ){
                sum+=dp[i][j];
            }

            if( sum<imin ){
                imin=sum;
                ans=names[i];
            }
        }

        cout << "Case #" << ++times << " : " << ans << '\n';
    }
}