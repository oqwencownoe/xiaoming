//上升子数列
#include <iostream>
#include <algorithm>
using namespace std;
int a[1010];
int b[1010];
int n;

int main(){
cin>>n;
for(int i=1;i<=n;i++){
  cin>>a[i];
}
b[1]=1;
for(int i=1;i<=n;i++){
  int q=0;
  for(int j=1;j<i;j++){
      if(a[i]>a[j]){
        q=max(q,b[j]);
      }

  }
  b[i]=q+1;
}

int ans=0;
for(int i=1;i<=n;i++){
  if(b[i]>ans){
    ans=b[i];
  }
}

for(int i=1;i<=n;i++){
  cout<<b[i]<<" ";
}
cout<<ans<<endl;
return 0;
}
