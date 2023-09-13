#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:

public:
    Node* head;
    LinkedList();
    void show();
    void insertnode(int num);//insert at the end of the linked list
    void insertnodefirst(int num);
    int numofelements();
    void insertatpos(int pos, int num);
    Node* searchbyval(int num);
    void delfirst();
    void dellast();
    void delbypos(int pos);
    void reverselist();
    void showrecursively(Node *temp);
    void showreverserecursively(Node *temp);
    void reverselistrecursively(Node *temp);
};

LinkedList:: LinkedList(){
    head = NULL;
}

void LinkedList:: insertnode(int num){
    Node* newnode = new Node;
    newnode -> data = num;
    newnode -> next = NULL;
    if (head == NULL){
        head = newnode;
        return;
        }
    else{
        Node* current = head;
        while(current -> next!= NULL){
            current = current -> next;
        }
        current -> next = newnode;
    }
}

void LinkedList:: insertnodefirst(int num){
    Node* newnode = new Node;
    newnode -> data = num;
    newnode -> next = NULL;
    if (head == NULL){
        head = newnode;
        head -> next = NULL;
        }
    else{
        newnode -> next = head;
        head = newnode;
    }
}

void LinkedList:: show(){
    Node* current = head;
    if (current == NULL)
        cout<<"Empty List"<<endl;
    else{
        while(current!=NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
}

int LinkedList:: numofelements(){
    Node* current = head;
    int cnt;
    while(current != NULL){
        cnt++;
        current = current -> next;
    }
    return cnt;
}

void LinkedList:: insertatpos(int pos, int num){
int n = numofelements();
if (pos ==0)
    insertnodefirst(num);
else if(pos == n)
    insertnode(num);
else if(pos<n){
    Node* newnode = new Node;
    newnode ->data = num;
    int cnt = 0;
    Node* prevnode = head;
    Node* nextnode = head;
    while(cnt!=pos){
        cnt++;
        prevnode = nextnode;
        nextnode = nextnode -> next;
    }
    prevnode->next=newnode;
    newnode->next=nextnode;
}
else
    cout<<"pos out of range"<<endl;
}

Node* LinkedList:: searchbyval(int value){
    Node* current = head;
    while(current!=NULL){
        while(current->data!=value){
            current = current->next;}
    return current;}
}

void LinkedList:: delfirst(){
    Node* copyhead = head;
    int n = numofelements();
    if (n==1){
        head = NULL;
        delete copyhead;
    }
    else if(n>1){
        head = head -> next;
        //copyhead -> next = NULL;
        delete copyhead;
    }
    else
        cout<<"list is empty"<<endl;
}

void LinkedList:: dellast(){
    Node* current = head;
    Node* prev = head;
    int n = numofelements();
    if (n==1){
        head = NULL;
        delete current;
    }
    else if(n>1){
        while(current -> next != NULL){
            prev = current;
            current = current -> next;
        }
        prev -> next = NULL;
        delete current;
    }
    else
        cout<<"list is empty"<<endl;

}

void LinkedList:: delbypos(int pos){
    int n = numofelements();
    if (pos == 0)
        delfirst();
    else if (pos ==n-1)
        dellast();
    else if(pos<n-1){
        int cnt = 0;
        Node* nextnode = head;
        Node* prevnode = head;
        while(cnt!=pos && nextnode!=NULL){
            cnt++;
            prevnode = nextnode;
            nextnode = nextnode -> next;
        }
        prevnode -> next = nextnode -> next;
        delete nextnode;
    }
    else
    cout<<"pos out of range"<<endl;
}

void LinkedList:: reverselist(){
    Node* current = head;
    Node* prev = NULL;
    Node* nextnode = NULL;
    while(current != NULL){
        nextnode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextnode;

    }
    head = prev;
    /*Node* li1 = new Node;
    li1->data = 1;
    Node* li0 = new Node;
    li0->data = 2;
    head=li1;
    li1->next = li0;
    li0->next = NULL;
    Node* li2 = new Node;
    li2->data = 3;
    Node* li00 = new Node;
    li00->data = 4;
    li2->next = li00;
    li00->next = NULL;
    li2->next = li1->next;
    li1->next->next=li1;
    li1->next=NULL;
    head=li2;*/

    /*Node* node1 = new Node;
    Node* node2 = new Node;
    node1 ->data = 1;
    node1->next = node2;
    head = node1;
    node2 ->data = 2;
    node2->next=NULL;
    Node* node3 = new Node;
    head->next->next = node3;
    node3->next = NULL;
    node3->data=3;
    Node* node4 = new Node;
    head->next->next = node4;
    node4->next = node3;
    node4->data=4;*/
}

void LinkedList:: showrecursively(Node *temp){
    if(temp == NULL){
        cout<<endl;
        return;
    }
    cout<< temp -> data<<" ";
    showrecursively(temp -> next);
}

void LinkedList:: showreverserecursively(Node *temp){
    if(temp == NULL){
        //cout<<endl;
        return;
    }
    showreverserecursively(temp -> next);
    cout<< temp -> data<<" ";
}

void LinkedList:: reverselistrecursively(Node *temp){
    if (temp -> next == NULL){
        head = temp;
        return;
    }
    reverselistrecursively(temp -> next);
    temp->next->next=temp;
    temp->next=NULL;
}

int main(){
    Node* fronti = new Node;
    fronti ->data = 1;
    Node* list2 = new Node;
    fronti ->next = list2;
    list2 ->data = 2;
    list2 ->next = NULL;
    Node* temp = new Node;
    Node* temp2 = new Node;
    Node* temp3 = new Node;
    temp ->data = 3;
    temp ->next = temp2;
    temp2 ->data = 4;
    temp2 ->next = temp3;
    temp3 ->data = 5;
    temp3 ->next = NULL;

    Node* current = fronti -> next;
    fronti -> next = temp ->next->next;
    temp ->next->next = fronti;
    current -> next = temp->next;
    temp -> next = current;
    fronti = temp;

    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }

    //cout<<temp ->next->next->data;


    return 0;
}
