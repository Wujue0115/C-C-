#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/extc++.h>
using namespace std;
#define io ios::sync_with_stdio(0); cin.tie(0);
#define Filex
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    io;
    #ifdef File
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    int k,n,End;
    pii polygons[512],temp;
    vector<pii> ans;

    function<int(pii)> Length=[&](pii a){
        return a.fi*a.fi + a.se*a.se;
    };

    function<int(pii,pii,pii)> Cross=[&](pii o,pii a,pii b){
        return ( a.fi-o.fi )*( b.se-o.se ) - ( a.se-o.se )*( b.fi-o.fi );
    };

    cin >> k;

    cout << k << '\n';
    while( k-- ){
        cin >> n;

        cin >> polygons[0].fi >> polygons[0].se;

        --n;
        for( int i=1 ; i<n ; ++i ){
            cin >> polygons[i].fi >> polygons[i].se;

            if( polygons[i].se<polygons[0].se || ( polygons[i].se==polygons[0].se && polygons[i].fi<polygons[0].fi) ){
                swap(polygons[0].fi,polygons[i].fi);
                swap(polygons[0].se,polygons[i].se);
            }
        }
        cin >> temp.fi >> temp.se;
        if( k ) cin >> End;

        sort(polygons+1,polygons+n,[&](const pii a,const pii b){
            if( Cross(polygons[0],a,b)!=0 ) return Cross(polygons[0],a,b)>0;
            return Length(a)>Length(b);
        });

        polygons[n]=polygons[0];

        ans.clear();
        ans.emplace_back(polygons[0]);
        ans.emplace_back(polygons[1]);
        for( int i=2 ; i<=n ; ++i ){
            while( ans.size()>2 && Cross(ans[ans.size()-2],ans[ans.size()-1],polygons[i])<=0 ){
                ans.pop_back();
            }

            ans.emplace_back(polygons[i]);
        }

        cout << ans.size() << '\n';
        for( const auto p:ans ){
            cout << p.fi << ' ' << p.se << '\n';
        }
        if( k ) cout << -1 << '\n';
    }
}