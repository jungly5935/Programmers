# 스택/큐 - 주식 가격

##
time벡터는 연산이 아무것도 이루어지지 않을경우 초기값으로 (price-1)부터 0까지 저장한다.  
만약 prices[i]보다 뒤에오는 prices[j]값이 더 작은것이 있을 경우, time[i]에는 j부터 i까지의 시간초 범위를 저장한다.  

### 코드

```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> time;

    for(int i=prices.size()-1;i>=0;i--) time.push_back(i);
    for(int i=0;i<time.size();i++){
        for(int j=i+1;j<time.size();j++){
            if(prices[i] > prices[j]) {
                time[i] =  j-i;
                break;
            }
        }
    }

    return time;
}

int main(int argc, const char *argv[])
{

    vector<int> prices;
  
//    prices.push_back(1);
//    prices.push_back(2);
//    prices.push_back(3);
//    prices.push_back(2);
//    prices.push_back(3);
//
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(1);
    
    solution(prices);
    
    return 0;
}

```
