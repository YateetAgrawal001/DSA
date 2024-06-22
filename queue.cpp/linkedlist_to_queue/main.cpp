#include<iostream>

using namespace std;
class Node{
public:
    int val;
    Node * next;
    Node(int val ){
        this->val = val;
        this-> next = NULL;
    }
};
class Queue{
public:
    int front=0;
    int rear=0;
    Node* head;
    Node* tail;
    int size;
    
    Queue(){
        head = tail = NULL;
        size=0;
    }
    void push(int val){
        Node * t = new Node(val);
        if(size==0) head = tail = t;
        tail -> next =t;
        tail = t;
        size++;
        
    }
    void pop()
    {
        head = head-> next;
        size--;
    }
    int back(){
        return tail->val;
    }
    int frunt(){
        return head->val;
    }
    int siize(){
        return size;
    }
    bool empty(){
        if(rear-front == 0 ) return true;
        else return false;
    }
    void display(){
        Node * temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp -> next;
        }
    }
            
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<q.frunt()<<endl;
    cout<<q.back()<<endl;
    cout<<q.siize()<<endl;
    q.pop();
    cout<<q.frunt()<<endl;
    cout<<q.back()<<endl;
   // cout<<q.size()<<endl;
    q.display();
    
}
