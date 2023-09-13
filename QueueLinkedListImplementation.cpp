#include <iostream>

using namespace std;
struct node{
    int num;
    node* next;
};

class Queue {
private:
    node* Front;
    node* rear;
public:
    Queue();
    bool isEmpty();
    void show();
    bool isFull();
    void enqueue(int v);
    int dequeue();
};

Queue::Queue(){
    Front = NULL;
    rear = NULL;
}

bool Queue::isEmpty(){
    if(Front == NULL && rear == NULL)
        return true;
    return false;
}

void Queue::show(){
    if(isEmpty())
        cout<<"empty queue"<<endl;
    else{
        node* current = Front;
        while(current != NULL){
            cout<< current->num<<" ";
            current=current->next;
        }
        cout<<endl;
    }
}

bool Queue::isFull(){
    node* newnode = new(nothrow) node; //nothrow makes newnode has NULL Value if stack is completed
    if (!newnode)
        return true;
    else{
        delete newnode;
        return false;
    }
}

void Queue::enqueue(int num){
    if(isFull())
        cout<<"full queue"<<endl;
    else{
        node* newnode = new node;
        newnode -> num = num;
        newnode -> next = NULL;
        if (Front == NULL && rear == NULL){
            Front = newnode;
            rear = newnode;
        }
        else{
            rear -> next = newnode;
            rear = newnode;
        }
    }
}

int Queue::dequeue(){
    if(isEmpty())
        cout<<"empty queue"<<endl;
    else if(Front == rear){
        int val = Front->num;
        node* temp = Front;
        Front = NULL;
        rear = NULL;
        delete temp;
        return val;
    }
    else{
        int val = Front -> num;
        node* temp = Front;
        Front = Front -> next;
        delete temp;
        return val;
    }
}

int main()
{
    Queue q;
    q.dequeue();
    q.enqueue(1);
    q.show();
    q.enqueue(2);
    q.show();
    q.enqueue(3);
    q.show();
    q.dequeue();
    q.show();
    q.enqueue(4);
    q.show();
    q.dequeue();
    q.show();
    q.dequeue();
    q.show();
    q.dequeue();
    q.show();
    q.enqueue(2);
    q.show();
    q.enqueue(3);
    q.show();
    return 0;
}
