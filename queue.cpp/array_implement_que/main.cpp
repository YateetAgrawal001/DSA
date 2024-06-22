#include<iostream>

using namespace std;
class Queue{
public:
    int front=0;
    int rear=0;
    int arr[5]; // for non-initialize space use "vector"
    
    Queue(){
    }
    void push(int val){
        if(rear ==5) {
            cout<<"queue is full --> overflow";
            return ;
        }
        arr[rear] = val;
        rear++;
    }
    void pop()
    {
        if(front-rear == 0) {
            cout<<"queue is empty --> underflow";
            return;
        }
        front++;
    }
    int back(){
        return arr[rear-1 ];
    }
    int frunt(){
        return arr[front];
    }
    int size(){
        return rear - front;
    }
    bool empty(){
        if(rear-front == 0 ) return true;
        else return false;
    }
    void display(){
        for(int i = front; i<rear;i++){
            cout<<arr[i]<<" ";
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
    //cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    //cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.display();
    
}
