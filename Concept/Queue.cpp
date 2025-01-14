#include <iostream>
#define Element int
using namespace std;

class Node
{
    public:
        Element data; 
        Node* next;    // 다음 노드를 가리키는 포인터

        Node(Element value) {
            data = value;
            next = nullptr;
        }
};

class Queue
{
    private:
        Node* front;
        Node* rear;   

    public:
        Queue()        { front = rear = nullptr; }
        bool isEmpty() { return front == nullptr; }

        void enqueue(Element value)
        {
            Node* newNode = new Node(value);

            if (isEmpty())  front = rear = newNode;
            else
            {   
                rear->next = newNode;
                rear = newNode;              
            }
        }

        
        Element dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue Underflow\n";
                return -1;
            }
            else
            {
                Element dequeuedValue = front->data;
                Node* temp = front;              
                front = front->next;             

                if (front == nullptr)   rear = nullptr;

                delete temp;
                return dequeuedValue;
            }
    }

    Element peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        else
            return front->data;

    }

    // 큐의 모든 요소를 출력하는 함수
    void display()
    {
        if (isEmpty())
            cout << "Queue is empty\n";
        
        else 
        {
            Node* current = front;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << '\n';
        }
    }

    ~Queue()
    {
        while (!isEmpty())
            dequeue();
    }
};

