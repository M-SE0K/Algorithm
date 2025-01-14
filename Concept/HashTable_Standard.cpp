#include <iostream>
#include <vector>

using namespace std;

class Node{
    private:
        int Key;
        int Value;
    public:
        void SetKey(int Key)     { this->Key = Key; }
        void SetValue(int Value) { this->Value = Value; }
        int getValue()           {return Value;}
};

class HashTable{
    private:
        int TableSize;
        Node* Table;
    public:
        HashTable* Create_HashTable (int TableSize)
        {
            HashTable* Ht = (HashTable*)malloc(sizeof(HashTable));
            Ht->Table = (Node*)malloc(sizeof(Node));
            Ht->TableSize = TableSize;

            return Ht;
        }
        void Set(HashTable* h, int Key, int Value)
        {
            int index = Hash(Key, h->TableSize);

            Table[index].SetKey(Key);
            Table[index].SetValue(Value);
            
        }
        int Get(HashTable* h, int Key)      { return h->Table[Hash(Key, TableSize)].getValue(); }

        int Hash(int Key, int TableSize)    {return Key % TableSize;}
        //Division Method 나눗셈법은 해시 함수 중에서 가장 간단한 알고리즘으로, 입력값을 테이블의 크기로 나누고 '나머지'를 테이블의 주소로 사용한다. 수식으로 표현하면 다음과 같다.
        
        void DestroyHashTable(HashTable* h)
        {
            free(Table);
            free(h);
        }
        int Hash(char* Key, int KeyLength, int TableSize)
        //Digits Folding(자릿수 접기) , 입력이 한 줄로 들어온 경우 문자열 형식으로 처리한 케이스임
        //아래의 경우 한 자리씩 끊어 계산한 경우이며, 이를 두 자리씩 세 자리씩 끊는 것은 본인의 마음임
        {
            int HashValue = 0;
            for (int i = 0; i < KeyLength; i++)
                //HashValue += Key[i]; 하지만 이 코드에는 문제가 있다. 해시테이블의 크기가 122289이고 문자열 키의 최대 길이가 10자리라고 한다면 해시 함수는 10 * 127 = 1270이므로 0~1270의 주소까지만 반환할 수 있다.
                //이러면 1271~12288 사이의 주소는 전혀 활용되지 않기에 이를 해결하기 위해 아스키 코드로 10자리를 만들었을 때를 생각했을 경우 12710가지의 경우의 수가 나온다. 이를 2진수로 표현하자면 총 14비트이며, 1270을 2진수로 표현하면 11비트의 경우의수가 나온다.
                //이를 종합하면 테이블의 주소 중 3개의 비트는 사용되지 않는다는 사실을 알 수 있다. 이를 이용하여 반복을 하여 값을 저장할 때마다 왼쪽으로 3비트씩 밀어 올린다면 이론 상 해시테이블 내의 모든 주소를 이용할 수 있다.
                HashValue = (HashValue) << 3 + Key[i];
            
            return HashValue % TableSize;
        }

};

int main()
{
    int Size;
    cin >> Size;

    HashTable* Ht;
    Ht = Ht->Create_HashTable(Size);

    int n;
    cin >> n;

    int key, value;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> key >> value;
        Ht->Set(Ht, key, value);

        ans.push_back(key);
    }

    for (int answer : ans)
        cout << "key : "<< answer << " Vlaue : "<< Ht->Get(Ht, answer) << '\n';
    
    Ht->DestroyHashTable(Ht);

    return 0;
}
