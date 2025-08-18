#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>




using namespace std;

vector<string> answer;
vector<char> vec;
int l, c;

string AEIOU = "aeiou";


void dfs(string ans, int cur, int consonant, int gather){

    //현재 위치의 문자열을 정답 문자열에 삽입하며, 현재 문자가 모음 or 자음인지에 대한 검사를 진행한다.
	ans.push_back(vec[cur]);
    if (AEIOU.find(vec[cur]) != string::npos)
        gather++;
    else
        consonant++;
        
	  //조합된 문자열(추측 문자열)이 주어진 암호의 길이와 동등해지는 경우
    if (ans.length() == l){
    
		    //자음, 모음 암호의 필수 요건이 충족되는 지 검사
        if(gather >= 1 && consonant >= 2)
            answer.push_back(ans);
        
        return;
    }
		
		//현재 위치에서부터 주어진 문자열의 끝까지 dfs 호출
    for (int i = cur + 1; i < c; i++)
        dfs(ans, i, consonant, gather);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> c;

    for (int i = 0; i < c; i++){
        char ch;
        cin >> ch;

        vec.push_back(ch);
    }
    
    sort(vec.begin(), vec.end());

    for (int i = 0; i <= c - l; i++){
        dfs("", i, 0, 0);
    }

    for (auto t : answer){
        cout << t << '\n';
    }
}