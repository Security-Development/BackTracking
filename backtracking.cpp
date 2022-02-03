#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int input;
vector<int> inputData;
vector<vector<string>> hashData;
vector<int> solutions;
vector<string> print;

// 숫자의 자릿수를 세는 함수
int calNumber(int number) {
    if( !number ){
        return 0;
    } else {
        return log10(number) + 1;
    }
}

// 입력된 값들을 쪼개어 각각에 배열에 담아주는 함수
void splitInputNumber() {
    inputData.resize(calNumber(input));
    int splitNumber = 0;
    int subData = input;
    vector<int> subVector;

    do {
        splitNumber = subData % 10;
        subData = subData / 10;
        subVector.push_back(splitNumber);
    }while (subData != 0);

    for(int i = subVector.size() -1 ; i >= 0; i--) {
        inputData.push_back(subVector[i]);
    }

    while(1){
        if(inputData[0] == 0) {
            inputData.erase(inputData.begin() + 0);
        } else {
            break;
        }
    }
    
}

// 백 트래킹을 진행하는 함수
void BT(int index) {
    if( index == calNumber(input)) {
        cout << print[0] << print[1];
        cout << endl;
        
        return;
    }
    
    int num = inputData[index];

    for(auto &item : hashData[num]) {
        print.push_back(item);        
        BT(index + 1);
        print.pop_back();
    }
}   

int main() {
    hashData.push_back(vector<string>({"", "", ""}));// 0번
    hashData.push_back(vector<string>({"a", "b", "c"}));// 1번
    hashData.push_back(vector<string>({"d", "e", "f"}));// 2번
    hashData.push_back(vector<string>({"g", "h", "i"}));// 3번

    // 값 입력
    cin >> input;

    splitInputNumber();

    BT(0);

    return 0;
} 