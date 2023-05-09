#include <iostream>
#include<chrono>
using namespace std;

struct node{
    
    int data;
    node *next_link;   
};
struct node *top=0;

bool isEmpty(){
    if(top==0){
        return true;
    }
    return false;
}

int StackTop(){
    if(isEmpty()){
        cout<<"stack is empty";
        exit(1);
    }
    return top->data;


}
void Push(int n){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next_link=top;
    top=newnode;
}
int Pop(){
    struct node *temp;
    temp= top;
    if(isEmpty()){
        cout<<"stack is empty";
        exit(1);
    }
    else{
        top=top->next_link;
        return temp->data;
    }
}
void Display(){
    struct node *temp;
    temp=top;
    if (top==0){
        cout<<"stack is empty";
    }
    else{
        while(temp!=0){
            cout<<temp->data<<endl;
            temp=temp->next_link;
            
        }
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
    cout<<"Taken time  is "<<duration.count()<<" microseconds\n";
    return 0;
}
