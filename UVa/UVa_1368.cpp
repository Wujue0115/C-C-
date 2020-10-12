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

    int t,n,m,ans,imax;
    char c;
    string s[50];
    multiset<char> cset[1000];

    cin >> t;
    while( t-- ){
        cin >> m >> n;

        for( int i=0 ; i<1000 ; ++i ){
            cset[i].clear();
        }

        for( int i=0 ; i<m ; ++i ){
            cin >> s[i];

            for( int j=0 ; j<n ; ++j ){
                cset[j].insert(s[i][j]);
            }
        }

        ans=0;
        for( int i=0 ; i<n ; ++i ){
            imax=0;
            for( int j='A' ; j<='Z' ; ++j ){
                if( cset[i].count(j)>imax ){
                    imax=cset[i].count(j);
                    c=char(j);
                }
            }
            cout << c;

            for( int j=0 ; j<m ; ++j ){
                if( c!=s[j][i] ){
                    ++ans;
                }
            }
        }   
        cout << '\n';
        cout << ans << '\n';     
    }
}