#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int v){
        val= v;
        this -> next =NULL;
    }
};

/*int main(){
    //10 20 30 40
    
    Node a;
    a.val = 10;
    Node b;
    b.val= 20;
    Node c;
    c.val =30;
    Node d;
    d.val = 40;
    
    
    // forming linked list
//    a.next = &b;
//    b.next = &c;
//    c.next = &d;
//    d.next = NULL;
//
    
    //using constructor
    
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    
//    Node *ptr = &b;
//    ptr->val = 60;
//    cout<<ptr->val<<endl;
    
    cout<<((a.next)->next)->next->val<<endl;
    
    Node temp = a;
    while(1){
        cout<<temp.val<<" ";
        if(temp.next==NULL) break;
        temp = *(temp.next);
    }
    
  }
*/

void display(Node* head){
    
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int count(Node* head){
   
    int n =0;
    while(head!=NULL){
        n++;
        head = head->next;
    }
    return n;
}


int main(){
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    //(*a).next = a->next
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    
//    Node *temp = a;
//    while(temp!=NULL){
//        cout<<temp->val<<" ";
//        temp = temp->next;
    
    display(a);
    cout<<count(a)<<endl;
    }
    

    
