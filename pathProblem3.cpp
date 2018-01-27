//第二个不高兴的小明
#include <iostream>
#include<algorithm>
using namespace std;
int h=100000;
int a[1010];
int F[1010][1010];
int main()
{
  int n,p,t;
  cin>>n>>p>>t;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  int m;
  a[0]=0;
  a[n+1]=0;
  F[0][0]=0;
  for(int i=0;i<=n+1;i++){
    for(int j=1;j<=t;j++){
      F[i][j]=-h;
    }
  }
  for(int i=1;i<=5;i++){
    F[i][1]=a[i];
  }

  for(int i=2;i<=t;i++){
    for(int j=1;j<=n+1;j++){
      int k=i-p;
      if(k>=0){
        for(int m=k;m<i;m++){
          if(F[m][i-1]+a[j]>F[j][i]){
            F[j][i]=F[m][i-1]+a[j];
          }
        }
      } else {
          for(int n=0;n<j;n++){
            if(F[n][i-1]+a[j]>F[j][i]){
              F[j][i]=F[n][i-1]+a[j];
            }
          }


      }
    }
  }
  int MAX=-h;
  for(int i=1;i<=t;i++){
    MAX=max(MAX,F[n+1][i]);
  }
  cout<<MAX<<endl;
  return 0;
}
