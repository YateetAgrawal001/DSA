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

class Linkedlist{
public:
    
    Node *head;
    Node * tail;
    int size;
    
    Linkedlist(){
        head = tail = NULL;
        size = 0;
    }
    
    void insertAtEnd(int val){
        Node * temp= new Node(val);
        if(size==0) {
            head=tail=temp;
 
        }
        else{
            tail->next = temp;
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
            head= temp;
        }
        size++;
    }
    
    void insertAtidx(int idx,int val){
       
        if(idx<0 || idx>size) cout<<"invalid index";
        else  if(idx==0)  insertAthead(val);
        
        else if(idx == size) insertAtEnd(val);
        
        else{
            Node * t= new Node(val);
            Node *temp = head;
            for(int i=1;i<idx;i++){
                temp = temp->next;
            }
             t->next =temp->next ;
            temp->next =t;
            
        }
            
        size++;
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
        else{
            temp = temp->next;
            size--;
        }
    }
    
    void deleteAtTail(){
        Node * temp = head;
        if(size==0) return ;
        while(temp->next!=tail ){
            temp=temp->next;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }
    
//    void deleteAtidx(int idx){
//        Node * temp = head;
//        if(idx<0 || idx>=size || size ==0) return;
//        else if(idx==0) deleteAthead();
//        else if(idx == size-1) deleteAtTail();
//        else{
//            for(int i =1;i<idx;i++) temp = temp->next;
//            temp->next = (temp->next)->next;
//            size--;
//        }
//    }
    void display(){
        
        while(head!=NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
};

int main(){

    Linkedlist ll;
    
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
//    ll.insertAtEnd(30);
//    ll.insertAthead(50);
//    ll.insertAtidx(2,80);
//    ll.display();
    //ll.deleteAtidx(3);
    ll.display();
    
    //cout<<ll.getAtidx(3);
    return 0;
}
