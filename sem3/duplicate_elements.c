//delete duplicate elements of array

#include<stdio.h>
int main(){
    int arr[10]={1,9,2,8,9,0,2,5,1,4};
    int size=10;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                for(int k=j;k<9;k++){
                    arr[k]=arr[k+1];
                }
                size--;
                j--;
            }
        }
    }

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}