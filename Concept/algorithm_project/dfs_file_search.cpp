#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 폴더 및 파일 구조 정의
struct Node
{
    string name;  // 폴더나 파일 이름
    bool isFile;  // 파일인지 폴더인지 구분
    vector<Node> children;  // 하위 디렉토리 및 파일

    Node(string n, bool isFile) : name(n), isFile(isFile) {}
};

// DFS로 특정 파일 찾기
bool dfs_search_file(Node& current, const string& targetFile)
{
    if (current.isFile && current.name == targetFile)
    {
        cout << "파일을 찾았습니다: " << current.name << '\n';
        return true;
    }

    // 하위 폴더나 파일 탐색
    for (auto& child : current.children)
        if (dfs_search_file(child, targetFile))
            return true;

    return false;  // 파일을 찾지 못하면 false 반환
}

int main() {
    // 파일 시스템 구조 생성
    Node root("root", false);  // 루트 디렉토리
    
    root.children.push_back(Node("folder1", false));
    root.children.push_back(Node("folder2", false));
    root.children.push_back(Node("file1.txt", true));

    root.children[0].children.push_back(Node("file2.txt", true));
    root.children[0].children.push_back(Node("file3.txt", true));
    root.children[1].children.push_back(Node("file4.txt", true));

    string targetFile;
    cout << "찾을 파일 이름을 입력하세요: ";
    cin >> targetFile;

    if (!dfs_search_file(root, targetFile)) {
        cout << "파일을 찾을 수 없습니다." << endl;
    }

    return 0;
}
