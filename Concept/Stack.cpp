#include <iostream>
#define Element int
#define MAX 100

using namespace std;
/*
배열
    -> 장점
        1. 직접 접근 가능 -> 배열은 인덱스를 사용하여 요소에 직접 접근할 수 있기에 빠른 읽기, 쓰기 성능을 가짐. 또한 특정 요소에 대한 접근이 O(1)임
        2. 간단한 구현 -> 배열 기반 스택과 큐는 구현이 상대적으로 단순함. 고정된 크기를 설정하기에 복잡한 메모리 관리가 필요 없음
    -> 단점
        1. 고정된 크기 : 크기를 특정하기 어려운 상황인 경우 Overflow 발생할 확률이 높음 -> 이로 인해 프로그램이 중단 됨!
                    이는 배열의 크기를 정적이 아닌 동적으로 할당한다고 한들 기존의 배열의 메모리에 대해 재할당하는 번거로움을 감수해야 함!
        2. 메모리 낭비 : 앞서 말한 상황과 동일한.. (크기를 특정하기 어려운~) 경우 필요 이상 보다 큰 배열을 생성한 경우 낭비 되는 상황이 발생함!
링크드 리스트
    -> 장점
        1. 동적 크기 조절 : 링크드 리스트는 필요한 만큼 노드를 동적으로 생성하므로, 미리 크기를 정하지 않아도 된다. -> 이 말은 즉, 크기의 제한이 없다
        2. 메모리 효율 : 고정된 크기가 아닌 상황에 맞추어 요소가 입력된 경우 노드를 바로바로 생성하기에 메모리 낭비가 발생하지 않는다.
        3. 삽입, 삭제 : 배열과 동일하게 삽입과 삭제의 O(1)이다. 단, 배열의 경우 삭제의 경우 배열처럼 데이터를 이동시키는 작업이 필요없다.(배열의 데이터를 옮기지 않고 링형으로 구성을 한다면? push 연산만 들어오는 경우를 생각하면 그딴 생각 못하게 됨.)
    -> 단점
        1. 직접 접근 불가 : 배열의 경우 O(1)의 접근을 보이지만, 링크드 리스트의 경우 root부터 tail까지의 list.size()번의 반복을 통해서야 접근이 가능하기에 O(N)을 가진다.
        2. 구현 복잡성 : 배열에 비해 구현이 복잡하다는 것은 있지만...?

*/
class Stack
//배열을 이용한 스택
{
private:
    Element arr[MAX]; // 스택 배열
    Element top;      

public:
    Stack()         {top = -1; }
    bool isEmpty()  {return top == -1;}
    bool isFull()   {return top == MAX - 1;}

    void push(Element value)
    {
        if (isFull())   cout << "Stack Overflow\n";
        else            arr[++top] = value;
    }

    Element pop() 
    {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        else            return arr[top--]; 
    }

    Element peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        } 
        else            return arr[top];
    }


    void display()
    {
        if (isEmpty())  cout << "Stack is empty\n";
        else
        {
            for (Element i = top; i >= 0; i--)
                cout << arr[i] << " ";
        }
            
        cout << std::endl;
    }
};


class Node
{
public:
    Element data;     
    Node* next;    // 다음 노드를 가리키는 포인터

    Node(Element value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
//링크드 리스트를 이용한 스택 구현
{
    private:
        Node* top;

    public:
        Stack()         {top = nullptr; }
        bool isEmpty()  {return top == nullptr;}

        void push(Element value)
        {
            Node* newNode = new Node(value); 
            newNode->next = top;             
            top = newNode;                   
        }

        Element pop()
        {

            if (isEmpty()) 
            {
                cout << "Stack Underflow\n";
                return -1;
            }
            else
            {
                Element poppedValue = top->data; 

                Node* temp = top;            
                top = top->next;             

                delete temp;                

                return poppedValue;          
            }
        }   


        Element peek()
        {
            if (isEmpty())
            {
                cout << "Stack is empty\n";
                return -1;
            }
            else            return top->data;
        }

        void display()
        {
            if (isEmpty())  cout << "Stack is empty\n";
            else
            {
                Node* current = top;
                while (current != nullptr)
                {
                    cout << current->data << " ";
                    current = current->next;
                }

                cout << std::endl;
            }
        }

        ~Stack()
        {
            while (!isEmpty())
                pop();
        }
};
