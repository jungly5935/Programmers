# 정렬 - 가장 큰  수

##
int 벡터인 numbers를 string으로 변환하여 str_numbers에 저장 후,  
sort함수로 비교 대상을 두개 더하여 더 큰 수를 앞에오게하여 내림차순으로 정렬했다. (string도 int처럼 대소 비교 가능)  
answer이 "00", "000", "0000" 등 모두 0인경우는 "0"으로 출력했다.


### 코드

```c++
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

bool compare(string a,string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_numbers;
    
    for(int i=0;i<numbers.size();i++)str_numbers.push_back(to_string(numbers[i]));
    sort(str_numbers.begin(), str_numbers.end(), compare);
    for(int i=0;i<numbers.size();i++) answer += str_numbers[i];
    if( count(answer.begin(), answer.end(), '0') == answer.length() ) answer = "0";
    return answer;
}

int main(int argc, const char *argv[])
{
    vector<int> numbers;
    
//    numbers.push_back(3);
//    numbers.push_back(30);
//    numbers.push_back(34);
//    numbers.push_back(5);
//    numbers.push_back(9);
    
//    numbers.push_back(6);
//    numbers.push_back(10);
//    numbers.push_back(2);
    
    numbers.push_back(0);
    numbers.push_back(0);
    numbers.push_back(0);

    solution(numbers);
    
    return 0;
}


```
