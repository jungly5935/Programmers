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
