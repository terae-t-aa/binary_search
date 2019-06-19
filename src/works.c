#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int s, w, i;
  s = 0;
  w = 0;
  for(i = 0; i < n; i++){
    if(w+A[i] > m){
      s = s + 1;
      w = 0;
    }
    if(A[i] <= m){
        w = w + A[i];
    }
    else{return 0;}
  }
  s = s + 1;
  return (int) s <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int m = (lb + ub) / 2;
    if(p(m)){
        ub = m;
    }
    else{
        lb = m;
    }
  }
  printf("%d¥n", ub);
  return 0;
}
