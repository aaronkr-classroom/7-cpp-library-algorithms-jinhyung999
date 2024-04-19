//split2.cpp
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>// fing_if()
#include <cctype>//isspace()

using namespace std;

//인수가 공백일때는 true, 그렇지 않을때는 false

static bool space(char c) {
	return isspace(c);
}

//인수가 공백일때는 flase, 그렇지 않을때는 true
static bool not_space(char c) {
	return !isspace(c);
}

static vector <string> split(const string& str) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector < string > ret;
	
	//for(iter i = str.begin();i!=str.end();i++) 와 비슷함
	while (i != str.end()) {
		cout << "str begin pos:" << distance(str.begin(), i) << endl;
		//선행공백을 무시
		// i위치부터 첫번째 띄어쓰기 아닌 문자 찾기
		i = find_if(i, str.end(), not_space);
		cout << "str find pos:" << distance(str.begin(), i) << endl;

		//다음 단어의 끝을 찾음
		//while 반복할 때 항상 새로운 반복자 j 를 생성
		// i위치부터 첫번째 띄어쓰기 문자 찾기

		iter j = find_if(i, str.end(), space);
		cout << "j pos:" << distance(str.begin(), j) << endl;

		//[i,j) 범위의 문자를 복사
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}
		
		//i반복자의 위치가 j 반복자의 위치를 저장하기
		i = j;
		cout << "i 이동 pos:" << distance(str.begin(), i) << endl;
	}
	return ret;
}

int main() {

	string s;

	// 문자열을 한 행씩 입력받아 분할
	while (getline(cin, s)) {
		vector<string> v = split(s);

		// 백터 v에 저장한 단어를 각각 출력
		for (vector<string>::size_type i = 0; i != v.size(); i++) {
			cout << v[i] << endl;
		}
	}

	return 0;
}