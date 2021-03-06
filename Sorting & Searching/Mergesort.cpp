#include <stdio.h>
#include <stdlib.h>
//

void Merge(int a[],int l,int m,int r){

int n1 = m - l + 1;
int n2 = (r - m);

int L[n1],R[n2];

for(int i = 0; i < n1; ++i){
  L[i] = a[l + i];
}
for(int j = 0; j < n2; ++j){
  R[j] = a[m + j + 1];
}

int i = 0,j = 0,k = l;

while(i < n1 && j < n2){
  if(L[i] <= R[j]){
    a[k] = L[i];
    i++;

   }
   else{
     a[k] = R[j];
     j++;

   }
   k++;
}

while(i < n1){
  a[k] = L[i];
  i++;
  k++;
}
while(j < n2){
  a[k] = R[j];
  j++;
  k++;
}



}
void Mergesort(int a[],int l,int r){
  if(l < r){
    int m = l + (r - l) / 2;

    Mergesort(a,l,m);
    Mergesort(a,m + 1,r);
    Merge(a,l,m,r);
  }
}
int main()
{
  int n;
   scanf("%d",&n);
  int *ar;
  ar = (int *)malloc(n*sizeof(int));
  for(int i = 0; i < n; ++i){
    scanf("%d",&ar[i]);
  }

  Mergesort(ar,0,n - 1);

  for(int i = 0; i < n; ++i){
    printf("%d ",ar[i]);
  }

  return 0;

}

//// second Approche /////

#include <stdio.h>

void Merge(arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int A[n1], B[n2];
  for(int i = 0; i < n1; ++i) {
      A[i] = arr[l + i];
  }

  for(int j = 0; j < n2; ++j) {
      B[j] = arr[m + j + 1];
  }

  int i = 0, j = 0, k = l;
  while(i < n1 or j < n2) {
      if(i == n1) {
        arr[k++] = B[j++];
      }
      else if(j == n2) {
        arr[k++] = A[i++];
      }
      else if(A[i] <= B[j]){
         arr[k++] = A[i++];
      }

      else{
        arr[k++] = B[j++];
      }
  }


}

void Mergesort(int arr[], int l, int r) {
  if(l < r) {
     int mid = (l + r) / 2;
     Mergesort(arr, l, mid);
     Mergesort(arr,mid + 1, r);
     Merge(arr, l, mid, r);
  }
}

int main() {
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i = 0; i < n; ++i) {
    scanf("%d",&arr[i]);
  }
  Mergesort(arr, 0, n - 1);
  for(int i = 0; i < n; ++i) {
    printf("%d ",arr[i]);
  }
  return 0;

}









