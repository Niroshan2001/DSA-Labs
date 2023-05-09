#include <iostream>
#include<cstdlib>
#include<algorithm>
#include<chrono>
 using namespace std; 
void quicksort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int pivot=arr[r];
    int i=l-1;
    int temp;
    for(int j=l;j<r;j++){
        if(arr[j]<=pivot){
        i++;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

        }
    }

    
    arr[r]=arr[i+1];
    arr[i+1]=pivot;
    int piv=i+1;
    quicksort(arr,l,piv-1);
    quicksort(arr,piv+1,r);
}


int main(){
    int n;
    cout<<"number of elements in the array:";
    cin>>n;
    int arr[n];
    for (int p=0;p<n;p++){
        arr[p]=rand() % 1000;
    }
    auto start=std::chrono::high_resolution_clock::now();
    quicksort(arr,0,n-1);
    auto end=std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout<<"time taken by quicksort "<<duration.count()<<" microseconds\n";
   
    
}