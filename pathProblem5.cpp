//数字三角形
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int g=100000;
int a[1010][1010];
int F[1010][1010];
int main() {
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      F[i][j]=-g;
    }
  }
  F[0][0]=a[0][0];
  for(int i=1;i<n;i++){
    a[i][0]+=a[i-1][0];
  }
  for(int i=1;i<n;i++){
    a[i][i]+=a[i-1][i-1];
  }
  for(int i=1;i<n;i++){
    F[i][0]=a[i][0];
  }
  for(int i=1;i<n;i++){
    F[i][i]=a[i][i];
  }
  for(int i=2;i<n;i++){
    for(int j=1;j<i;j++){
      F[i][j]=max(F[i-1][j-1]+a[i][j],F[i-1][j]+a[i][j]);
    }
  }
  int ans=0;
  for(int j=0;j<n;j++){
    if(F[n-1][j]>ans){
      ans=F[n-1][j];
    }
  }
  cout<<ans<<endl;
  return 0;
}
