#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
private:
    int* arr;
    int maxsize;
    int heapsize;
public:
    MaxHeap(int maxsize);
    void MaxHeapify(int i, int n);
    int removemax();
    void increasekey(int i, int newval);
    void deletekey(int i);
    void insertkey(int x);
    void breadthfirst();
    void heapsort();
    bool isheap(int i);
    bool isheap2();
    void klargest(int k);
    void printgreaterthan(int, int);
    void maxtomin(int Size);
    void MinHeapify(int i, int Size);
    void buildmaxheap(int Size);

    int parent(int i){
        return (i-1)/2;
    }
    int lchild(int i){
        return 2 * i + 1;
    }
    int rchild(int i){
        return 2 * i + 2;
    }
    int getmax(){
        return arr[0];
    }
    int currsize(){
        return heapsize;
    }
    int height(){
        return floor(log2(heapsize));
    }
};

MaxHeap::MaxHeap(int maxsize){
    heapsize = 0;
    maxsize = maxsize;
    arr = new int[maxsize];
}

void MaxHeap::insertkey(int x){
    if (heapsize == maxsize){
        cout<<"Overflow: could not insert key"<<endl;
        return;
    }
    int i = heapsize;
    arr[heapsize] = x;
    heapsize++;
    while(i!=0 && arr[parent(i)] < arr[i]){
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }

}

void MaxHeap::increasekey(int i, int newval){
    arr[i] = newval;
    while(i!=0 && arr[parent(i)] < arr[i]){
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }

}

void MaxHeap::MaxHeapify(int i, int n){
    int l = lchild(i);
    int r = rchild(i);
    int largest = i;
    if(l < n && arr[l] > arr[i])
        largest = l;
    if(r < n && arr[r] > arr[i])
        largest = r;
    if(largest != i){
        swap(arr[i],arr[largest]);
        MaxHeapify(largest, n);
    }
}

int MaxHeap::removemax(){
    if (heapsize <= 0)
        return INT_MIN;
    if (heapsize == 1){
        heapsize--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heapsize - 1];
    heapsize--;
    MaxHeapify(0,heapsize);
    return root;
}

void MaxHeap::deletekey(int i){
    increasekey(i, INT_MAX);
    removemax();
}

void MaxHeap::breadthfirst(){
    /*if(heapsize == 0){
        cout<<"empty tree";
        return;
    }
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int i = q.front();
        if(lchild(i) < heapsize)
            q.push(lchild(i));
        if(rchild(i) < heapsize)
            q.push(rchild(i));
        cout<< arr[i] <<" ";
        q.pop();
        }
        cout<<endl;*/
        for(int i = 0; i < heapsize; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
}

void MaxHeap::heapsort(){
    for(int i = heapsize - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        MaxHeapify(0, i);
    }
    for(int i = 0; i < heapsize; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool MaxHeap::isheap(int i){
    if(i >= (heapsize - 1) / 2)
        return true;
    if(arr[i] >= arr[lchild(i)] &&
       arr[i] >= arr[rchild(i)] &&
       isheap(lchild(i)) && isheap(rchild(i)))
        return true;
    return false;
}

bool MaxHeap::isheap2(){
    for(int i = 0; i <= (heapsize - 2) / 2; i++){
        if(lchild(i) < heapsize && arr[lchild(i)] > arr[i])
            return false;
        if (rchild(i) < heapsize && arr[rchild(i)] > arr[i])
            return false;
    }
    return true;
}

void MaxHeap::klargest(int k){
    if(k > heapsize){
        cout<<"invalid value of k";
        return;
    }
    heapsort();
    for(int i = heapsize - 1; i > heapsize - k - 1; i--)
        cout<<arr[i]<<" ";
    for(int i = (heapsize / 2 - 1); i >= 0 ; i--){
        MaxHeapify(i, heapsize);
    }
    cout<<endl;
}

insertionsort(int arr2[], int Size){//o(n*k) time
    int i, key, j;
    for (int i = 1; i < Size; i++){
        key = arr2[i];
        j = i - 1;
        while(j >= 0 && arr2[j] > key){
            arr2[j+1] = arr2[j];
            j = j - 1;
        }
        arr2[j+1] = key;
    }
    for(i=0; i<Size; i++)
      cout<<arr2[i]<<" ";

  cout<<endl;
}

void sortnearlysorted2(int arr2[], int Size, int k){//o(nk)
//where each element is at most K away from its target position  O(N log K) time
    int i, key, j;
    for (int i = 1; i < Size; i++){
        key = arr2[i];
        j = i - 1;
        while(j >= max(i - k,0) && arr2[j] > key){
            arr2[j+1] = arr2[j];
            j = j - 1;
        }
        arr2[j+1] = key;
    }
    for(i=0; i<Size; i++)
      cout<<arr2[i]<<" ";

  cout<<endl;
}

void MaxHeap::printgreaterthan(int n, int i){
    if (arr[i] < n)
        return;
    cout<<arr[i]<<" ";
    printgreaterthan(n, lchild(i));
    printgreaterthan(n, rchild(i));
    /*for (int j = 0; j < heapsize; j++){
        if (arr[j] > n)
            cout<<arr[j]<<" ";
        else
            return;
    }*/
}

void MaxHeap::maxtomin(int Size){
    for (int i = (Size - 2) / 2; i >= 0; i--)
        MinHeapify(i,Size);
}

void MaxHeap::MinHeapify(int i, int Size){
    int smallest = i;
    if(lchild(i) < heapsize && arr[i] > arr[lchild(i)])
        smallest = lchild(i);
    if(rchild(i) < heapsize && arr[i] > arr[rchild(i)])
        smallest = rchild(i);
    if(smallest != i){
        swap(arr[i],arr[smallest]);
        MinHeapify(smallest, Size);
    }
}

void MaxHeap::buildmaxheap(int Size){
    for (int i = (Size - 2) / 2; i >= 0; i--)
        MaxHeapify(i,Size);
}

int main(){
    MaxHeap h(15);
    h.insertkey(3);
    h.insertkey(10);
    h.insertkey(12);
    h.insertkey(8);
    h.insertkey(2);
    h.insertkey(14);
    h.breadthfirst();
    cout<<h.isheap2()<<endl;
    //cout<<h.currsize();
    h.klargest(4);
    h.breadthfirst();
    cout<<h.height()<<endl;
    int A[] = {6, 5, 3, 2, 8, 10, 9};
    int Size = 7;
    insertionsort(A, Size);
    int A2[] = {2, 6, 3, 12, 56, 8};
    int Size2 = 6;
    int k = 2;
    sortnearlysorted2(A2, Size2 , k);
    h.printgreaterthan(4,0);
    cout<<endl;
    h.maxtomin(h.currsize());
    h.breadthfirst();
    h.buildmaxheap(h.currsize());
    h.breadthfirst();
    return 0;
}
