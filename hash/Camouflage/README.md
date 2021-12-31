# 해시 - 위장

##
main함수는 예제 디버깅을 위해 추가했다. 답은 solution만 해당.  
clothes 2차원 string 벡터 배열에는 [옷, 카테고리]순서대로 저장되어있다.  
unordered_map 벡터를 이용해 pair[1]번째 요소 (카테고리)가 같은것을 모아 개수를 저장하고,  
iterator i를 이용해 개별 카테고리 개수를 +1한 값에, 카테고리별로 곱해준 후, 전체에서 -1을 해준다. 
ex) 답 = (카테고리1 옷개수 + 1)*(카테고리2 옷개수 +1) - 1

### 코드

```c++
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

```
