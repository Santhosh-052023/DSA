#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int lo, int hi){
int temp;
int pivot = a[lo];
while(hi > lo){
    while(a[lo] < pivot){
        lo++;
    }
    while(a[hi] > pivot){
        hi--;
    }
    if(hi > lo){
        temp = a[hi];
        a[hi] = a[lo];
        a[lo] = temp;
    }
    else{
     temp = pivot;
     pivot = a[hi];
     a[hi] = temp;   
    }
}
return hi;
}

void quick_sort_recur(int a[], int lo, int hi){
if(lo > hi){
    return;
}else{
    int p = partition(a,lo,hi);
    quick_sort_recur(a,lo,p-1);
    quick_sort_recur(a,p+1,hi);
}
}

int main(){
    int a[] = {10,15,1,2,9,16,11};
    int n = sizeof(a) / sizeof(a[0]);
    //int aux[n];

    quick_sort_recur(a, 0, n - 1);

    int i = 0;
    while (i < n) {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    return 0;
}
