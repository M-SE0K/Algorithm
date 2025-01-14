// #include <iostream>
// #include <vector>

// using namespace std;

// class Node {
//     private:
//         int data;
//     public:
//         void setData(int x) {
//             data = x;
//         }
//         int getData() {
//             return data;
//         }
// };

// class Heap {
//     private:
//         vector<Node> nodes;
//         int UsedSize = 0;
//     public:
//         int getParent(int index) {
//             return (index - 1) / 2;
//         }
//         int getLeftChild(int index) {
//             return index * 2 + 1;
//         }
//         void nodeSwap(int index1, int index2) {
//             swap(nodes[index1], nodes[index2]);
//         }
//         void push(int x) {
//             Node newNode;
//             newNode.setData(x);
//             nodes.push_back(newNode);
//             UsedSize++;

//             int current = UsedSize - 1;
//             int parent = getParent(current);

//             while (current > 0 && nodes[current].getData() < nodes[parent].getData()) {
//                 nodeSwap(current, parent);
//                 current = parent;
//                 parent = getParent(current);
//             }
//         }
//         bool isEmpty() {
//             return UsedSize == 0;
//         }
//         int pop() {
//             if (isEmpty()) return 0;

//             int ans = nodes[0].getData();
//             nodeSwap(0, UsedSize - 1);
//             nodes.pop_back();
//             UsedSize--;

//             int current = 0;
//             while (true) {
//                 int leftPosition = getLeftChild(current);
//                 int rightPosition = leftPosition + 1;
//                 int selected = current;

//                 if (leftPosition < UsedSize && nodes[leftPosition].getData() < nodes[selected].getData()) {
//                     selected = leftPosition;
//                 }
//                 if (rightPosition < UsedSize && nodes[rightPosition].getData() < nodes[selected].getData()) {
//                     selected = rightPosition;
//                 }
//                 if (selected == current) break;

//                 nodeSwap(current, selected);
//                 current = selected;
//             }

//             return ans;
//         }
// };

// int main() {
//     int n, x;
//     cin >> n;

//     Heap H;
//     vector<int> answer;
//     for (int i = 0; i < n; i++) {
//         cin >> x;
//         if (x != 0)
//             H.push(x);
//         else
//             answer.push_back(H.pop());
//     }

//     for (int ans : answer)
//         cout << ans << '\n';

//     return 0;
// }
