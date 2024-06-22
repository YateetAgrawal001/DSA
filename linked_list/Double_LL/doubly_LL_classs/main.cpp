#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node * next;
    Node * prev;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Doubly_LL{
public:
    Node *head;
    Node * tail;
    int size;
    
    Doubly_LL(){
        head = tail = NULL;
        size = 0;
    }
    
    void insertAttail(int val){
        Node * temp= new Node(val);
        if(size==0) {
            head=tail=temp;
 
        }
        else{
            tail->next = temp;
            //temp->next = NULL;
            temp->prev = tail; //imp line
            tail= temp;
        }
        size++;
    }
    
    void insertAthead(int val){
        Node * temp= new Node(val);
        if(size==0) {
            head=tail=temp;
 
        }
        else{
            temp->next = head;
            head->prev = temp;  // imp line
            head = temp;
        }
        size++;
    }
    
    void insertAtidx(int idx,int val){
       
        if(idx<0 || idx>size) cout<<"invalid index";
        else  if(idx==0)  insertAthead(val);
        
        else if(idx == size) insertAttail(val);
        
        else{
            Node * t= new Node(val);
            Node *temp = head;
            for(int i=1;i<idx;i++){
                temp = temp->next;
            }
            t->next =temp->next ;
            temp->next =t;
            t->prev = temp;
            t->next->prev = t;
            size++;
        }
    }
    
    int getAtidx(int idx){
        //Node * temp= new Node(val);
        if(idx<0 || idx>=size) return -1;
        else if(idx == 0) return head->val;
        else if(idx == size-1) return tail->val;
        else{
            Node * temp = head;
            for(int i =1;i<=idx;i++){
                temp = temp->next;
                
            }
            return temp->val;
        }
        
    }
    
    void deleteAthead(){
        Node * temp = head;
        if(size ==0 ) return;
        //temp = temp -> next;  yaha debug krne ko dikha error h logic yhi h lekin
        if(temp) temp->prev =NULL;
        if(temp==NULL ) tail = NULL;
        size--;
    }
    
    void deleteAtTail(){
        Node * temp = tail->prev;
        if(size==0) return ;
        if(size==1){
            deleteAthead();
            return;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }
    
    void deleteAtidx(int idx){
        Node * temp = head;
        if(idx<0 || idx>=size || size ==0) return;
        else if(idx==0) deleteAthead();
        else if(idx == size-1) deleteAtTail();
        else{
            for(int i =1;i<idx;i++) temp = temp->next;
            temp->next = (temp->next)->next;
            size--;
        }
    }
    void display(){
        
        while(head!=NULL){
            cout<<head->val<<" ";
            head = head->next;
            
        }cout<<endl;
    }
};
int main() {
    Doubly_LL ll;
    ll.insertAttail(10);
    ll.insertAttail(20);
    ll.insertAthead(30);
    ll.insertAthead(40);
    ll.insertAtidx(2, 50);
    ll.display();
    //ll.deleteAthead();
    ll.deleteAtTail();
    ll.display();
    
}
