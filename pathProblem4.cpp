//第三个不高兴的小明
#include<iostream>
#include<algorithm>
using namespace std;
int a[1010][1010];
int F[1010][1010];
const int u=100000;
int main() {
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n;i++){
    for(int j=0;j<q;j++){
      cin>>a[i][j];
    }
  }

  for(int i=0;i<=n;i++){
    for(int j=0;j<=q;j++){
      F[i][j]=-u;
    }
  }
  for(int i=1;i<q;i++){
    a[0][i]+=a[0][i-1];
  }
  for(int i=1;i<n;i++){
    a[i][0]+=a[i-1][0];
  }

  for(int i=1;i<q;i++){
    F[0][i]=a[0][i];
  }

  for(int j=1;j<n;j++){
    F[j][0]=a[j][0];
  }

  F[0][0]=a[0][0];

  for(int i=1;i<n;i++){
    for(int j=1;j<q;j++){
      F[i][j]=max(F[i-1][j]+a[i][j],F[i][j-1]+a[i][j]);
    }
  }


  cout<<F[n-1][q-1]<<endl;
  return 0;
}
