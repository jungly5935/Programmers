#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string ,int> hash;
    for(vector<string> pair : clothes ){
        hash[pair[1]]++;
    }
    
    unordered_map <string ,int>::iterator i;
    for(i=hash.begin();i!=hash.end();i++){
        answer *= i -> second+1;
    }
    return answer-1;
    
}

int main(int argc, const char *argv[])
{
    vector<vector<string>> clothes;
    vector<string> cloth;
    vector<string> cloth2;
    vector<string> cloth3;
    
    cloth.push_back("yellow_hat");
    cloth.push_back("headgear");
    cloth2.push_back("blue_sunglasses");
    cloth2.push_back("eyewear");
    cloth3.push_back("green_turban");
    cloth3.push_back("headgear");
    
    clothes.push_back(cloth);
    clothes.push_back(cloth2);
    clothes.push_back(cloth3);
    
    int answer = solution(clothes);
    
    cout << answer;
    return 0;
}
