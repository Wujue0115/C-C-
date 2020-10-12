#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/extc++.h>
using namespace std;
#define io ios::sync_with_stdio(0); cin.tie(0);
#define Filex
#define fi first
#define se second

typedef long long ll;
typedef pair<int,string> pis;

int main(){
    io;
    #ifdef File
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    int s,p,d,n;
    char ei,ej,ek,em;
    pis dp[26][26];

    while( cin >> s >> p ){
        for( int i=0 ; i<s ; ++i ){
            fill(dp[i],dp[i]+s,make_pair(51200,char(i+65)));

            for( int j=0 ; j<s ; ++j ){
                if( i!=j ){
                    dp[i][j].se.push_back(char(j+65));
                }
            }
        }

        while( p-- ){
            cin >> ei >> ej >> d;

            dp[ei-65][ej-65].fi=dp[ej-65][ei-65].fi=d;
        }

        for( int k=0 ; k<s ; ++k ){
            for( int i=0 ; i<s ; ++i ){
                for( int j=0 ; j<s ; ++j ){
                    if( dp[i][k].fi+dp[k][j].fi<dp[i][j].fi ){
                        dp[i][j].fi=dp[i][k].fi+dp[k][j].fi;
                        dp[i][j].se=dp[i][k].se;
                        if( k!=j ){
                            dp[i][j].se.insert(dp[i][j].se.end(),dp[k][j].se.begin()+1,dp[k][j].se.end());
                        }
                    }
                }
            }
        }

        cin >> n;
        while( n-- ){
            cin >> ek >> em;

            ek-=65; em-=65;
            for( int i=0 ; i<dp[ek][em].se.size() ; ++i ){
                if( i ) cout << ' ';
                cout << dp[ek][em].se[i];
            }
            cout << '\n';
        }
    }
}