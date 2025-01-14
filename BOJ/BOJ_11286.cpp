
//배열에 정수 x (x ≠ 0)를 넣는다.
//배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node{
private:
    int Data;
public:
    int getData()           {return Data;}
    void setNode(int Data)  {this->Data = Data;}

};

class Heap{
private:
    Node* Nodes;
    int Capacity;
    int UsedSize;
    int getParent(int Index)            {return (int)((Index - 1) / 2);}
    int getLeftChild(int Index)         {return (Index * 2) + 1;}
    void Swap(Node& node1, Node& node2)
    {
        Node temp = node1;
        node1 = node2;
        node2 = temp;
    }
    
public:
    Heap(int Capacity)
    {
        this->Capacity = Capacity;
        this->UsedSize = 0;
        this->Nodes = (Node*)malloc(sizeof(Node) * this->Capacity);
    }
    ~Heap(){
        free(Nodes);
    }

    void push(Heap* H, int Data)
    {
        if (H->Capacity == H->UsedSize)
        //현재 Heap의 용량이 꽉찬 경우 메모리 재할당을 진행한다.
        {
            H->Capacity = H->Capacity * 2;
            H->Nodes = (Node*)realloc(H->Nodes, sizeof(Node) * H->Capacity);
        }
        
        int Current = H->UsedSize;
        int Parent = H->getParent(Current);
        
        H->Nodes[Current].setNode(Data);
        
        while(0 < Current)
        //새로 추가될 노드의 위치를 찾기 위해 말단의 노드에서부터 시작해 자리를 찾을 때까지 노드들의 자리를 바꿔준다.
        {
            if (abs(H->Nodes[Current].getData()) < abs(H->Nodes[Parent].getData()) ||
                (abs(H->Nodes[Current].getData()) == abs(H->Nodes[Parent].getData()) &&
                 H->Nodes[Current].getData() < H->Nodes[Parent].getData()))
                //Current 노드의 절대값이 parent 노드의 절대값이 더 작거나, 두 노드의 절대값이 같으며 Current : -, Parent : +인 경우 배열에 삽입을 진행한다.
            {
                Swap(H->Nodes[Current],H->Nodes[Parent]);
                Current = Parent;
                Parent = H->getParent(Current);
            }
            else
                break;
        }
        
        H->UsedSize++;
        //반복이 종료되었다면 push연산이 올바르게 진행된 것이기에 노드의 총 개수를 1 증가 시킨다.
    }
    bool isEmpty(Heap* H)
    {
        if (H->UsedSize == 0)   return true;
        else                    return false;
    }
    int pop(Heap* H)
    {
        if (isEmpty(H))  return 0;
        //삭제할 노드가 존재하지 않는 다면 문제의 조건대로 0을 반환한다.
        
        int result = Nodes[0].getData();
        Nodes[0] = Nodes[UsedSize - 1];
        UsedSize--;
        //배열에서 절대값이 가장 작은 값을 출력하기 위해 root 노드의 값을 result에 저장한다. 이후 pop연산을 위해 root 노드에 leaf 노드의 주소값을 저장한다.
        
        int Current = 0;
        while(true)
        {
            int Left = getLeftChild(Current);
            int Right = Left + 1;
            int Selected = Current;
            
            if (Left < H->UsedSize &&
                (abs(Nodes[Left].getData()) < abs(Nodes[Selected].getData()) ||
                 (abs(Nodes[Left].getData()) == abs(Nodes[Selected].getData()) && Nodes[Left].getData() < Nodes[Selected].getData())))
            //Left가 총 노드의 개수에서 벗어나지 않으면서, Selected 노드가 자식 노드 보다 절대값이 작거나 혹은 두 노드의 절댓값이 같으면서 두 노드의 부호가 서로 다른 경우
            {
                Selected = Left;
            }
            if (Right < H->UsedSize &&
                (abs(Nodes[Right].getData()) < abs(Nodes[Selected].getData()) ||
                 (abs(Nodes[Right].getData()) == abs(Nodes[Selected].getData()) && Nodes[Right].getData() < Nodes[Selected].getData())))
            {
                Selected = Right;
            }
            if ( Selected == Current)   break;
            
            Swap(Nodes[Current], Nodes[Selected]);
            Current = Selected;
        }
        
        return result;
    }
};

int main()
{
    int n, x;
    cin >> n;
    
    Heap* H = new Heap(n);
    
    vector<int> answer;
    
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        
        if (x != 0)
            H->push(H, x);
        else
        {
            if (H->isEmpty(H))  answer.push_back(0);
            else                answer.push_back({H->pop(H)});
        }
    }
    for (auto ans : answer)
        cout << ans << '\n';
    delete H;
    
    return 0;
}
