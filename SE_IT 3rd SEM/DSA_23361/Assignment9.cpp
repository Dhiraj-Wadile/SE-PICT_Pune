#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int root){
    int largest=root;
    int lchild=2*root+1;
    int rchild=2*root+2;
    if(lchild<n && arr[lchild]>arr[largest]){
        largest=lchild;
    }
    if(rchild<n && arr[rchild]>arr[largest]){
        largest=rchild;
    }
    if(largest!=root){
        swap(arr[root],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapify1(int arr[],int n,int root){
    int smallest=root;
    int lchild=2*root+1;
    int rchild=2*root+2;
    if(lchild<n && arr[lchild]<arr[smallest]){
        smallest=lchild;
    }
    if(rchild<n && arr[rchild]<arr[smallest]){
        smallest=rchild;
    }
    if(smallest!=root){
        swap(arr[root],arr[smallest]);
        heapify(arr,n,smallest);
    }
}
void maxheap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--) {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void minheap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify1(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify1(arr,i,0);
    }
}
void display(int arr[],int n){
    cout<<"Your sorted list"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of Array: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the Element"<<i+1<<endl;
        cin>>arr[i];
    }
    int choice;
    do{
        cout<<"1.For MaxHeap\n2.For Minheap\n3.Exit";
        cout<<"Enter your choice";
        cin>>choice;
        switch (choice){
            case 1:
                maxheap(arr,n);
                display(arr,n);
                cout<<endl;
                break;

            case 2:
                minheap(arr,n);
                display(arr,n);
                cout<<endl;
                break;

            case 3:
                break;
        }
    }while(choice!=3);
}
