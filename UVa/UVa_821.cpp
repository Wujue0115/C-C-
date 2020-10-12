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

    int times=0,a,b;
    int dp[101][101];
    unordered_set<int> iset;
    double ans;

    while( cin >> a >> b && a|b ){
        for( int i=1 ; i<=100 ; ++i ){
            fill(dp[i]+1,dp[i]+101,100);
        }
        iset.clear();

        dp[a][b]=1;
        iset.insert(a); iset.insert(b);
        while( cin >> a >> b && a|b ){
            dp[a][b]=1;
            iset.insert(a); iset.insert(b);
        }

        for( const int &k:iset ){
            for( const int &i:iset ){
                for( const int &j:iset ){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }

        ans=0;
        for( const int &i:iset ){
            for( const int &j:iset ){
                if( i!=j ){
                    ans+=dp[i][j];
                }
            }
        }

        cout << "Case " << ++times << ": average length between pages = ";
        cout << fixed << setprecision(3) << ans/(iset.size()*(iset.size()-1)) << " clicks\n";
    }
}