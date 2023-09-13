#include <iostream>
#include <queue>
using namespace std;
#define MAX_TREE_HT 100

struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq){
        this -> left = this -> right = NULL;
        this -> data = data;
        this -> freq = freq;
    }
};

struct MinHeap {
    unsigned Size;
    unsigned capacity;
    // Array of minheap node pointers
    MinHeapNode** arr;

    MinHeap(unsigned capacity){
        this -> Size = 0;
        this -> arr = new MinHeapNode*;
        this -> capacity = capacity;
    }
};

void minHeapify(MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->Size && minHeap->arr[left]->freq < minHeap->arr[smallest]->freq)
        smallest = left;
    if (right < minHeap->Size && minHeap->arr[right]->freq < minHeap->arr[smallest]->freq)
        smallest = right;
    if (smallest != idx){
        swap(minHeap->arr[smallest], minHeap->arr[idx]);
        minHeapify(minHeap, smallest);
    }
}

MinHeapNode* extractMin(MinHeap* minHeap){
    MinHeapNode* temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->Size - 1];
    --minHeap->Size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap,MinHeapNode* minHeapNode){
    ++minHeap->Size;
    int i = minHeap->Size - 1;
    while (i && minHeapNode->freq < minHeap->arr[(i - 1) / 2]->freq){
        minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->arr[i] = minHeapNode;
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i];
    cout << "\n";
}

// Creates a min heap of capacity equal to size and inserts all character of data[] in min heap.
MinHeap* createAndBuildMinHeap(char data[],int freq[], int Size){
    MinHeap* minHeap = new MinHeap(Size);
    for (int i = 0; i < Size; ++i)
        minHeap->arr[i] = new MinHeapNode(data[i], freq[i]);
    minHeap-> Size = Size;
    int n = minHeap->Size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[],int freq[], int Size){
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, Size);
    while (minHeap->Size != 1){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[],int top){
    if (root->left) {
        arr[top] = 1;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 0;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)){
        cout << root->data << ": ";
        printArr(arr, top);
    }
}
void breadthfirst(MinHeapNode* root){
    if(root == NULL){
        cout<<"empty tree";
        return;
    }
    queue<MinHeapNode*> q;
    q.push(root);
    while(!q.empty()){
        MinHeapNode* current = q.front();
        if(current -> left != NULL)
            q.push(current -> left);
        if(current -> right != NULL)
            q.push(current -> right);
        cout<< current -> data<<" ";
        q.pop();
        }
        cout<<endl;
}

void HuffmanCodes(char data[], int freq[], int Size){
    MinHeapNode* root = buildHuffmanTree(data, freq, Size);
    int arr[MAX_TREE_HT], top = 0;
    //breadthfirst(root);
    printCodes(root, arr, top);
}

int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    /*char arr[] = { 'H','u','f'};
    int freq[] = { 1,11,20};
    int Size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, Size);*/
    //char arr3[] = { 'a', 'b', 'c', 'd', 'e'};
    //int freq3[] = { 4,    2,   2,  1  ,  1};
    //int Size3 = sizeof(arr3) / sizeof(arr3[0]);
    //HuffmanCodes(arr3, freq3, Size3);
    //char arr4[] = { 'H', 'u', 'f', 'm', 'a', 'n',' ', 'i', 's','e','c'};
    //int freq4[] = { 1,    1,   2,  1,    2,  3,   3,   2,   1,  1,   1};
    //int Size4 = sizeof(arr4) / sizeof(arr4[0]);
    //HuffmanCodes(arr4, freq4, Size4);
    /*string text = "Huffman is a decoding algrithm";
    int n = sizeof(text)/sizeof(text[0]);
    int visited[n];
    int freq[n];
    char arr[n];
    int m = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if(visited[i] != 1){
           freq[m] = 1;
           arr[m] = text[i];
           for(int j = i + 1; j < n; j++){
              if(text[i] == text[j]){
                 freq[m]++;
                 visited[j] = 1;
              }
            }
            m++;
         }
     }
     //for(int i = 0; i < m; i++)
     //   cout<<"'"<<arr[i]<<"',";
    //for(int i = 0; i < m; i++)
    //    cout<<freq[i]<<",";
     HuffmanCodes(arr, freq, m);
     //cout<<n;
     //for(int i = 0; i < m; i++)
     //   cout<<arr[i]<<" "<<freq[i]<<endl;*/
    return 0;
}
