#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
int left_child=2*root+1;
int right_child=2*root+2;
int large;
if(left_child<n && arr[left_child]>arr[root]){
   large=left_child;
}
else{
   large=root;
}
if(right_child<n && arr[right_child]>arr[large]){
   large=right_child;
}
if(large!=root){ // child is geater than parent.
   swap(arr[large],arr[root]);
   heapify(arr,n,large);
}
   
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int j=(n/2-1);j>=0;j--){//hepify non leaf nodes.
      heapify(arr,n,j);
   }
  
   // extracting elements from heap one by one
   
   for(int i=0;i<n;i++){
      swap(arr[0],arr[n-1-i]); 
      heapify(arr,n-1-i,0); //heapify the root element of the tree.

   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n;
   cout<<"Input the size of the array:";
   cin>>n;
   int heap_arr[n];
   for(int i=0;i<n;i++){
      cin>>heap_arr[i];
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}