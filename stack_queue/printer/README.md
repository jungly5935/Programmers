# 스택/큐 - 프린터

##
prior벡터 안에 받은 입력과 인덱스를 같이 저장해두고,  
prior의 첫번째요소보다 큰것이 있으면 , 첫번째요소를 마지막에 넣고 첫번째자리에서는 지운다.  
처음 자리에 한해서 모든 경우를 계속 봐야하므로 , 한번 push erase가 일어나면 i=0으로해줘서 다시 비교한다.
result 벡터에는 반복문이 한번 끝날때마다 prior의 첫번째 요소를 넣어준다.  
인덱스는 0부터 시작하지만 결과 값은 1부터 시작하므로 , location으로 주어진 값과 result[i].second의 인덱스가 같을 때 i+1가 답이 된다.

### 코드

```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> prior;
    vector<pair<int,int>> result;
    
    for(int i=0;i<priorities.size();i++) prior.push_back(make_pair(priorities[i], i));
    
    while(!prior.empty()){
        for(int i=1;i<prior.size();i++){
            if(prior[0].first < prior[i].first){
                prior.push_back(prior[0]);
                prior.erase(prior.begin());
                i=0;
            }
        }
        result.push_back(prior[0]);
        prior.erase(prior.begin());
    }
    for(int i=0;i<priorities.size();i++){
        if(location == result[i].second) {
            return i+1;
        }
    }
    return answer;
}

int main(int argc, const char *argv[])
{
    vector<int> priorities;
    int location = 2;

    priorities.push_back(2);
    priorities.push_back(4);
    priorities.push_back(8);
    priorities.push_back(2);
    priorities.push_back(9);
    priorities.push_back(3);
    priorities.push_back(3);

    solution(priorities, location);
    
    return 0;
}
```