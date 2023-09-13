#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data){
    this -> data = data;
    this -> left = NULL;
    this -> right = NULL;
    }
};

class BinaryTree{
public:
    node* root;
    int nodecount;
    BinaryTree();
    node* addnode(node*, int);
    bool searchtree(node*, int);
    int findmin(node*);
    node* findminptr(node*);
    int findmax(node*);
    int findminrecursively(node*);
    int findheight(node*);
    node* findnode(node*, int);
    void breadthfirst(node*);
    void depthfirst(node*);// pre-order
    void depthfirstrecursively(node*);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    bool isbst(node*);
    bool isbstutil(node*, int minval, int maxval);
    node* delnode(node*,int);
    int succesor(node* root, int data);
    int maxpathsum(node*);
    int treesum(node*);
    void inorderTraversal(node* root, vector<int>& arr);
    void BSTToMinHeap(node* root, vector<int> arr, int* i);
    void convertToMinHeap(node* root);
};

BinaryTree::BinaryTree(){
    root = NULL;
    nodecount = 0;
}

node* BinaryTree::addnode(node* root, int data){
    node* newnode = new node(data);
    if (root == NULL){
        root = newnode;
        nodecount++;
    }
    else if(data >= root -> data)
        root -> right = addnode(root -> right, data);
    else if(data <= root -> data)
        root -> left = addnode(root -> left, data);
    return root;
}

bool BinaryTree::searchtree(node* root, int data){
    if (root == NULL)
        return false;
    else if(data == root -> data)
        return true;
    else if(data >= root -> data)
        return searchtree(root -> right, data);
    else
        return searchtree(root -> left, data);
}

int BinaryTree::findmin(node* root){
    if(root == NULL){
        cout<<"empty tree";
        return -1;
    }
    else{
        while(root -> left != NULL)
            root = root -> left;
        return root -> data;
    }
}

node* BinaryTree::findminptr(node* root){
    if(root == NULL){
        cout<<"empty tree";
        return NULL;
    }
    else{
        while(root -> left != NULL)
            root = root -> left;
        return root;
    }
}

int BinaryTree::findmax(node* root){
    if (root == NULL){
        cout<<"Empty Tree"<<endl;
        return -1;
    }
    while(root -> right != NULL){
        root = root -> right;
    }
    return root -> data;
}

int BinaryTree::findminrecursively(node* root){
    if(root == NULL){
        cout<<"empty tree";
        return -1;
    }
    else if(root -> left == NULL)
        return root -> data;
    findminrecursively(root -> left);
}

int BinaryTree::findheight(node* root){
    if (root == NULL)
        return -1;
    else{
        //int lheight = findheight(root->left);
        //int rheight = findheight(root->right);
        //int maxsum = max(lheight,rheight)+1;
        //cout<<maxsum<<" ";
        //return maxsum;
        return max(findheight(root->left),findheight(root->right))+1;
    }
}

node* BinaryTree::findnode(node* root, int data){
    if(root == NULL)
        return NULL;
    else if(root -> data == data)
        return root;
    else if(data > root -> data)
        findnode(root -> right, data);
    else
        findnode(root -> left, data);
}

void BinaryTree::breadthfirst(node* root){
    if(root == NULL){
        cout<<"empty tree";
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* current = q.front();
        if(current -> left != NULL)
            q.push(current -> left);
        if(current -> right != NULL)
            q.push(current -> right);
        cout<< current -> data<<" ";
        q.pop();
        }
        cout<<endl;
}

void BinaryTree::depthfirst(node* root){
    if(root == NULL)
        return;
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* current = s.top();
        s.pop();
        cout<<current -> data<<" ";
        if(current -> right != NULL)
            s.push(current->right);
        if(current -> left != NULL)
            s.push(current->left);
    }
    cout<<endl;
}

void BinaryTree::depthfirstrecursively(node* root){
    if(root == NULL)
        return;
    else{
        cout<<root->data<<" ";
        depthfirstrecursively(root->left);
        depthfirstrecursively(root->right);
    }
}

void BinaryTree::inorder(node* root){
    if(root == NULL)
        return;
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void BinaryTree::postorder(node* root){
    if(root == NULL)
        return;
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void BinaryTree::preorder(node* root){
    if(root == NULL)
        return;
    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

bool BinaryTree::isbst(node* root){
    return isbstutil(root, INT_MIN, INT_MAX);
}

bool BinaryTree::isbstutil(node* root, int minval, int maxval){
    if(root == NULL)
        return true;
    if(root -> data > minval && root -> data < maxval
       && isbstutil(root->left, minval, root -> data)
       && isbstutil(root->right, root -> data, maxval))
        return true;
    return false;
}

node* BinaryTree::delnode(node* root, int data){
    if (root == NULL)
        return root;
    else if(data < root -> data)
        root -> left = delnode(root -> left, data);
    else if (data > root -> data)
        root -> right = delnode(root -> right, data);
    else{
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            root = NULL;
            nodecount--;
            return root;
        }
        else if (root -> left == NULL){
            node* temp = root;
            root = root -> right;
            delete temp;
            nodecount--;
        }
        else if(root -> right == NULL){
            node* temp = root;
            root = root -> left;
            delete temp;
            nodecount--;
        }
        else{
            node* temp = findminptr(root -> right);
            root -> data = temp -> data;
            root -> right = delnode(root -> right, temp -> data);
        }
    }
    return root;
}

int BinaryTree::succesor(node* root, int data){
    node* current = findnode(root,data);
    if (current == NULL)
        return -1;
    if (current -> right != NULL){
        //node* temp = current -> right;
        //while(temp -> left != NULL)
         //   temp = temp -> left;
        //return temp -> data;
        return findmin(current -> right);
    }
    else{
        node* succesor = NULL;
        node* ancestor = root;
        while(ancestor != current){
            if(current -> data < ancestor -> data){
                succesor = ancestor;
                ancestor = ancestor -> left;
            }
            else
                ancestor = ancestor -> right;
        }
        return succesor->data;
    }
}

int BinaryTree::maxpathsum(node* root){
    if(root == NULL)
        return INT_MIN;
    if(root -> left == NULL && root -> right == NULL)
        return root->data;
    int maxsum = max(maxpathsum(root -> left),maxpathsum(root -> right));
    //cout<< maxsum<<" ";
    return maxsum + root -> data;
}

int BinaryTree::treesum(node* root){
    if (root == NULL)
        return 0;
    if(root -> right == NULL && root -> left == NULL)
        return root -> data;
    return treesum(root -> left) + treesum(root -> right) + root -> data;
}

void BinaryTree::inorderTraversal(node* root, vector<int> &arr){
    if (root == NULL)
        return;
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

void BinaryTree::BSTToMinHeap(node* root, vector<int> arr, int* i){
    if (root == NULL)
        return;
    // first copy data at index 'i' of 'arr' to the node
    root->data = arr[++*i];
    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}

void BinaryTree::convertToMinHeap(node* root){
    // vector to store the data of all the nodes of the BST
    vector<int> arr;
    int i = -1;
    inorderTraversal(root, arr);
    BSTToMinHeap(root, arr, &i);
}


int main(){
    BinaryTree t;
    node* root = NULL;
    /*
    //cout<<root<<"a"<<endl;
    root = t.addnode(root,9);
    //cout<<root<<"b"<<endl;
    root = t.addnode(root,5);
    //cout<<root<<"c"<<endl;
    root = t.addnode(root,4);
    //cout<<root<<"d"<<endl;
    root = t.addnode(root,6);
    //cout<<root<<"e"<<endl;
    root = t.addnode(root,12);
    //cout<<root<<"f"<<endl;
    root = t.addnode(root,11);
    //cout<<root<<"g"<<endl;
    //root = t.addnode(root,92);
    root = t.addnode(root,10);
    //cout<<root<<"h"<<endl;
    cout<<t.searchtree(root,6)<<endl;
    //cout<<root<<"i"<<endl;
    cout<<t.searchtree(root,8)<<endl;
    //cout<<root<<"j"<<endl;
    cout<<t.findmin(root)<<endl;
    //cout<<root<<"k"<<endl;
    cout<<t.findminptr(root)<<endl;
    //cout<<root<<"l"<<endl;
    cout<<t.findminrecursively(root)<<endl;
    cout<<t.findmax(root)<<endl;
    cout<<t.findheight(root)<<endl;
    t.breadthfirst(root);
    t.depthfirstrecursively(root);
    cout<<endl;
    t.depthfirst(root);
    cout<<t.findnode(root,11)<<endl;
    cout<<t.findnode(root,22)<<endl;
    t.inorder(root);
    cout<<endl;
    cout<<t.isbst(root)<<endl;
    cout<<t.nodecount<<endl;
    //t.delnode(root,11);
    //cout<<t.nodecount<<endl;
    //t.inorder(root);
    //cout<<endl;
    cout<<t.succesor(root,11)<<endl;
    cout<<t.nodecount<<endl;
    cout<<t.maxpathsum(root)<<endl;
    cout<<t.treesum(root)<<endl;
    t.convertToMinHeap(root);
    t.breadthfirst(root);*/
    /*node* root = NULL;
    root = t.addnode(root,15);
    root = t.addnode(root,12);
    root = t.addnode(root,17);
    root = t.addnode(root,10);
    root = t.addnode(root,20);
    t.breadthfirst(root);
    root = t.delnode(root,15);
    t.breadthfirst(root);
    root = t.delnode(root,20);
    t.inorder(root);*/
    /*root = t.addnode(root,15);
    root = t.addnode(root,23);
    root = t.addnode(root,20);
    root = t.addnode(root,10);
    root = t.addnode(root,13);
    root = t.addnode(root,6);
    root = t.addnode(root,18);
    root = t.addnode(root,35);
    root = t.addnode(root,9);
    root = t.addnode(root,24);
    cout<<t.findheight(root)<<endl;
    t.preorder(root);
    cout<<endl;
    t.postorder(root);
    cout<<endl;
    t.inorder(root);
    cout<<endl;
    t.breadthfirst(root);
    t.delnode(root,6);
    t.delnode(root,15);
    t.delnode(root,20);
    t.breadthfirst(root);*/
    root = t.addnode(root,2);
    root = t.addnode(root,0);
    root = t.addnode(root,1);
    root = t.addnode(root,10);
    root = t.addnode(root,9);
    root = t.addnode(root,12);
    t.breadthfirst(root);
    return 0;
}
