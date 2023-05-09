#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

void insertion(int arr[],int j){
    for(int z=j-1;z>=0;z--){
        if(arr[z]<arr[j]){
            break;
            }
        
        else{
            swap(arr[z],arr[j]);
            j=z;
        }
    }
}
double median(int arr[],int len){
    double med;
    if(len%2!=0){
        med=arr[len/2];
        
    }
    else{
        med=(arr[len/2]+arr[(len/2)-1])/2.0;
        }
        return med;
}
int main(){

cout<<"number of elements: ";
int n;
cin>>n;
int arr[n];

for(int j=0;j<n;j++){
    cin>>arr[j];
    insertion(arr,j);
    int len =j+1;
    cout<<"Sorted Array[ ";
    for(int k=0;k<=j;k++){
        cout<<arr[k]<<" ";
    }
    double med =median(arr,len);
    cout<<"]Median: "<<fixed<<setprecision(1)<<med<<endl;
    

    }
return 0;
}

