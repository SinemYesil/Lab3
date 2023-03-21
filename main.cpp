#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    struct Node{
        int data;
        Node* next;
        Node(int x): data(x),next(nullptr){}
    };

    Node* front;
    Node*rear;
    int numElements;
public:
    Queue(){
        front = nullptr;
        rear = nullptr;
        numElements=0;
    }

    bool isEmpty() {
        return front== nullptr;
    }

    void enqueue(int x){
        Node* temp= new Node(x);
        if(isEmpty()) {
            front=rear=temp;
        }
        else {
            rear-> next =temp;
            rear=temp;

            }
        numElements++;

    }
    void dequeue(){
        if(isEmpty()){
            cout<< "Queue is empty."<<endl;
            return;
        }
        Node*temp=front;
        front=front-> next;
        delete temp;
        numElements--;


    }
    int top(){
        if (isEmpty()){
            cout<<"Queue is empty."<< endl;
            return -1;
        }
        return front-> data;
    }
    int size(){
        return numElements;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return;
        }
        Node* temp= front;
        while (temp!= nullptr){
            cout<<temp-> data<<"-";
            temp=temp->next;

        }
        cout<<endl;
    }


};


int main() {
    Queue s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.display();
    s.dequeue();
    s.display();
    cout<< "Top:" << s.top()<<endl;
    cout<< "Size:"<< s.size()<<endl;
    return 0;


}


