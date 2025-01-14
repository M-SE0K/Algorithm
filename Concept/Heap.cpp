#include "HEAP.h"

using namespace std;
Heap* Heap_Create(int Initialize);
void Heap_Destroy(Heap* h);
void Heap_Insert(Heap* H, ElementType NewData);
void Heap_DeleteMin(Heap* H, HeapNode* Root);
int Heap_GetParent(int Index);
int Heap_GetLeftChild(int Index);
void Heap_SwapNodes(Heap* H, int Index1, int Index2);
void Heap_PrintNodes(Heap* H);

Heap* Heap_Create(int Initialize)
//힙을 초기에 생성하는 메서드로 객체 내부의 멤버 변수에 대한 초기화 작업이 진행 된다.
{
    Heap* NewHeap = (Heap*)malloc(sizeof(Heap));                //Heap크기만큼의 메모리를 동적 할당하고 이를 강제 형변환을 통해 할당 받은 주소값의 형태로 넘긴다.
    NewHeap->Capacity = Initialize;                             //초기화할 즉, 힙의 총 크기에 대해 정의하는 것이다.
    NewHeap->UsedSize = 0;                                      //총 HeapNode의 개수를 의미한다.
    cout << "size : " << sizeof(Heap) << '\n';

    return NewHeap;                                             //생성된 힙을 반환한다. (주소값)
}

void Heap_Destroy(Heap* h)
//삭제할 힙을 인자로 받아옴. 메모리 해제는 생성의 역순으로 진행 된다.
{
    free(h->Nodes);
    free(h);
}

void Heap_Insert(Heap* H, ElementType NewData)
//삽입할 노드, 해당 힙의 루트 노드를 인자로 받아온다.
{
    int CurrentPosition = H->UsedSize;                          //Current -> 현재 가장 말단에 위치한 노드의 위치이기에 H->UsedSize의 값을 받아온다.
    int ParentPosition = Heap_GetParent(CurrentPosition);       //Current의 위치를 기반으로 Current의 부모노드의 위치를 저장한다.

    if (H->UsedSize == H->Capacity)                             //생성 당시 할당한 메모리의 용량이 남았는 지에 대한 검사를 진행 후 만약 메모리가 남지 않았다면 삽입이 정상적으로 이루어지지 않게 되기에 이를 방지하는 차원에서 검사 진행 후 재할당 하든지 한다.
    {
        H->Capacity *= 2;                                       //임의로 메모리의 용량을 2배로 증가시킨 것. 증가 시키는 것은 sizeof(HeapNode) * n만큼 본인이 원하는 대로 지정하면 된다. 여기서는 편의상 2배로 통일 시켰다.
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;

    while(CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
    //모든 노드에 대해 탐색을 마친 경우이거나, 자신 보다 부모 노드의 Data값이 더 작은 경우 반복을 멈춘다.
    {
        Heap_SwapNodes(H, CurrentPosition, ParentPosition);     //Current가 Parent의 Data 값 보다 작기에 최소힙의 조건에 위배된다. 그러기에 두 Heap의 위치를 바꾸어 준다.

        CurrentPosition = ParentPosition;
        ParentPosition = Heap_GetParent(CurrentPosition);
        //두 위치를 저장하는 변수를 업데이트 해줌.
    }

    H->UsedSize++;                                              //총 힙의 개수를 1만큼 증가 시킨다.
}
void Heap_SwapNodes(Heap* H, int index1, int index2)
{
    int copysize = sizeof(HeapNode);
    HeapNode* temp = (HeapNode*)malloc(copysize);

    memcpy(temp, &H->Nodes[index1], copysize);
    memcpy(&H->Nodes[index1], &H->Nodes[index2], copysize);
    memcpy(&H->Nodes[index2], temp, copysize);

    free(temp);
}
void Heap_DeleteMin(Heap* H, HeapNode* Root)
//가장 말단에 위치한 노드와 루트 노드의 자리를 바꾸ㅣ어 삭제한 이후 말단의 노드의 위치를 위에서부터 아래로 업데이트 하는 과정을 거친다.
{
    int ParentPosition, CurrentPosition, Left_Position, Right_Position;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));               //Root(새로운 루트, 현재는 말단의 주소가 담겨 있음)에 현재 루트 노드의 주소를 저장한다.
    memset(&H->Nodes[0], 0, sizeof(HeapNode));                  //기존의 루트 노드의 주소를 0 or NULL로 초기화해준다.

    H->UsedSize--;
    Heap_SwapNodes(H, 0, H->UsedSize);

    Left_Position = Heap_GetLeftChild(0);
    Right_Position = Left_Position + 1;

    while(1)
    {
        int SelectedChild = 0;
        if (Left_Position >= H->UsedSize)  break;               
        if (Right_Position >= H->UsedSize) SelectedChild = Left_Position;
        //위의 두 조건문은 저장된 각각의 자식 노드의 위치가 범위에 벗어나는 지에 대한 확인이다.

        else
        //각가의 자식 노드의 위치가 범위에 벗어나지 않기에 두 자식 노드 중 작은 값을 찾아 SelectedChild에 저장한다.
        {
            if (H->Nodes[Left_Position].Data > H->Nodes[Right_Position].Data)     SelectedChild = Right_Position;
            else                                                                  SelectedChild = Left_Position;
        }

        if(H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
        //두 노드가 최소힙의 조건에 위배되는 경우 두 노드의 위치를 바꿔준다.
        {
            Heap_SwapNodes(H, SelectedChild, ParentPosition);
            ParentPosition = SelectedChild;
        }
        else
        //두 노드가 최소힙의 조건에 위배되지 않는다면 트리의 균형이 맞춰진 것이기에 반복을 종료한다.
            break;

        Left_Position = Heap_GetLeftChild(SelectedChild);
        Right_Position = Left_Position + 1;
    }

    if (H->UsedSize < (H->Capacity / 2))                        //힙의 사용된 크기가 전체 용량의 절반으로 줄어든다면, 힙의 용량을 절반으로 줄인다.
    {
        H->Capacity /= 2;                       
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
}

int Heap_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int Heap_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

void Heap_PrintNodes(Heap* H)
{
    for (int i = 0; i < H->UsedSize; i++)
    {
        cout << H->Nodes[i].Data;
    }
    cout << '\n';
}