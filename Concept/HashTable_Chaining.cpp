#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Node
{
    private:
        string key;
        string value;
        Node* next;
    public:
        void Set(string key, string value)
        {
            this->key = key;
            this->value = value;
        }
        Node* CreateNode(string key, string value)
        {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->key = key;
            newNode->value = value;

            return newNode;
        }
        void SetNext(Node* n)   { this->next = n; }
        Node* getNext()         { return this->next; }
        string getValue()       { return this->value; }
        string getKey()         { return this->key; }
};

class HashTable{
    private:
        int TableSize;
        Node** Table;
        //이중 포인터를 사용하는 이유는 해시 테이블에서 충돌이 발생할 때, 각 해시 테이블 슬롯이 링크드 리스트의 시작 지점을 가리켜야 하기 때문이다. 이해가 안 되는 경우엔 체이닝 기법일 때 구조를 이미지로 생각해보기.
        //만약 Node* 타입을 사용한다면 해시 테이블의 각 슬롯은 단 하나의 Node 객체만을 가리킬 수 있다. 이런 경우 앞서 말한 대로 충돌이 발생한 경우 해당 슬롯에 다른 노드를 추가할 수 없게 만든다.
    public:
        HashTable* CreateHashTable(int TableSize)
        {
            HashTable* h = (HashTable*)malloc(sizeof(HashTable));
            h->TableSize = TableSize;
            Node** Talbe = (Node**)malloc(sizeof(Node) * TableSize);

            memset(h->Table, 0, sizeof(Node) * TableSize);

            return h;
        }
        void DestroyHashTable(HashTable* h)
        {
            free(Table);
            free(h);
        }
        void Set(HashTable* h, string key, string value)
        {
            int index = Hash(key, TableSize);
            Node* newNode;
            newNode = newNode->CreateNode(key, value);

            if (h->Table[index] == NULL)    h->Table[index] = newNode;
            else
            {
                Node* n = Table[index];
                newNode->SetNext(n);
                h->Table[index] = newNode;
            }
        }
        string Get(string key)
        {
            /*
            1. 찾고자 하는 목표값을 해싱하여 링크드 리스트가 저장된 주소를 찾는다.
            2. 이 주소를 이용하여 해시 테이블에 저장된 링크드 리스트에 대한 포인터를 생성한다.
            3. 링크드 리스트의 앞에서부터 뒤까지 차례대로 이동하며 목표값이 저장되어 있는 지 비교한다. 목표값과 링크드 리스트 내 노드 값이 일치하면 해당 노드의 주소를 반환한다.
            */
            int index = Hash(key, TableSize);
            Node* Chaining = Table[index];
            Node* Target = NULL;

            if (Chaining == NULL)               return "error!";
            if (Chaining->getNext() == NULL)    return Chaining->getValue();
            //찾고자 하는 목표값에 노드가 존재하지 않는 다면 값을 반환할 수 없다. 또한 해당 인덱스의 노드가 Chaining 하나뿐이라면 탐색을 종료하고 현재 노드의 value 값을 반환한다.
            
            while(1)
            {
                if (Chaining->getKey() == key)
                //원하는 값을 찾았을 때 Target에 현재 노드 주소를 저장하고 반복을 중단한다.
                {
                    Target = Chaining;
                    break;
                }

                if (Chaining->getNext() == NULL)    break;
                //원하는 값을 찾지 못한 경우, 다음 노드로 반복해야 하지만  현재 노드가 말단 노드인 경우 반복을 중단한다. 존재하지 않는 key가 들어온 경우에 대한 처리도 필요해 보임

                else                                Chaining = Chaining->getNext();
                //다음 노드의 주소를 Chaining에 저장하고 반복을 진행한다.
            }

            return Target->getValue();
        }
        int Hash(string key, int TableSize)
        {
            int HashValue = 0;
            for (int i = 0; i < key.length(); i++)
                HashValue += (HashValue << 3) + key[i];
                //HashValue += Key[i]; 하지만 이 코드에는 문제가 있다. 해시테이블의 크기가 122289이고 문자열 키의 최대 길이가 10자리라고 한다면 해시 함수는 10 * 127 = 1270이므로 0~1270의 주소까지만 반환할 수 있다.
                //이러면 1271~12288 사이의 주소는 전혀 활용되지 않기에 이를 해결하기 위해 아스키 코드로 10자리를 만들었을 때를 생각했을 경우 12710가지의 경우의 수가 나온다. 이를 2진수로 표현하자면 총 14비트이며, 1270을 2진수로 표현하면 11비트의 경우의수가 나온다.
                //이를 종합하면 테이블의 주소 중 3개의 비트는 사용되지 않는다는 사실을 알 수 있다. 이를 이용하여 반복을 하여 값을 저장할 때마다 왼쪽으로 3비트씩 밀어 올린다면 이론 상 해시테이블 내의 모든 주소를 이용할 수 있다.

            return HashValue % TableSize;
        }

        int main()
        { 
            int Size;
            cin >> Size;

            HashTable* h = CreateHashTable(Size);

            int n;
            cin >> n;
            
            vector<string> ans;
            string key, value;
            for (int i = 0; i < n; i++)
            {
                cin >> key >> value;
                h->Set(h, key, value);

                ans.push_back(key);
            }

        }
};