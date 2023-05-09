#include <iostream>
#include<chrono>
using namespace std;

const int  len=10;
int stack_array[len];
int top=-1;
bool isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}
bool isFull(){
    if(top==len-1){
        return true;
    }
    return false;
}
void Push(int num){
    if (isFull()){
        cout<<"stack_array overflow\n";
        return;
    }
    
        top++;
        stack_array[top]=num;
    
}

int Pop(){
    if(isEmpty()){
        cout<<"stack_array underflow\n";
        exit(1);
    }
    
    int data=stack_array[top];
    top--;
    return data;
   
}
int StackTop(){
    if(isEmpty()){
        cout<<"stack_array underflow \n";
        exit(1);
    }
    return stack_array[top];
}

void Display(){
    for(int i=0;i<=top;i++){
        cout<<stack_array[i]<<endl;
    }
}
int main(){
 auto start=std::chrono::high_resolution_clock::now();  
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);    
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);
    Pop();
    Pop();
    Display();
    StackTop();
    Push(rand() % 1000);
    Push(rand() % 1000);
    Push(rand() % 1000);
    Pop();

auto end=std::chrono::high_resolution_clock::now();
auto duration=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
cout<<"Taken time is   "<<duration.count()<<" microseconds\n";    
}
