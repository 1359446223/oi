#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN=100010,MOD=99999997;

typedef long long ll;

struct match{
  int a,b;
}h[MAXN];

int N,X[MAXN],c[MAXN],a[MAXN],xnum=0;

ll count1();
bool cmp(match,match);

int main(){
  cin >> N;
  for (int i=1;i<=N;++i) scanf("%d",&h[i].a);
  for (int i=1;i<=N;++i) scanf("%d",&h[i].b);
  sort(h+1,h+1+N,cmp);
  for (int i=1;i<=N;++i){
    a[i]=h[i].a;
    X[++xnum]=a[i];
  }
  cout << count1() << endl;
}

bool cmp(match m1,match m2){return m1.b<m2.b;}

ll count1(){
  ll ans=0;
  for (int i=1;i<N;++i)
    for (int j=i+1;j<=N;++j)
      if (a[j]<a[i]) ans=(ans+1)%MOD;
  return ans;
}
