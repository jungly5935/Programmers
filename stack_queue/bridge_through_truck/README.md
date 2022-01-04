# 스택/큐 - 다리를 지나는 트럭

##
queue로 선언한 q에다 truck_weights입력을 넣어두고 시작한다.  
`for(int i=1; i != q.empty() ; i++ )` 여기서 i는 경과 시간으로 생각한다.  
weight보다 time벡터 원소의 모든합(t)이 작을때만 q를 push할 수 있다.  
index에는 time에 q 원소가 언제 들어왔는지를 저장한다.  
q 원소는 bridge_length 시간동안만 존재할 수 있으므로 bridge_length 값과 i-index.front()이 같을때는 time에서 q원소를 제거한다. 마찬가지로 index도 함께 제거한다.  
마지막 경과시간은 마지막으로 들어온 시간(i)으로부터 bridge_length-1를 더해주면 구할 수 있다.  


### 코드

```c++
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    vector<int> time;
    vector<int> index;
    for(int i=0;i<truck_weights.size();i++) q.push(truck_weights[i]);
    
    index.push_back(1);
    for(int i=1; i != q.empty() ; i++ ){
        
        if(q.empty()) return i+=(bridge_length-1);
        
        if(bridge_length == i-index.front()) { //time은 bridge_length의 시간초만큼 존재, 그이후는 erase
            index.erase(index.begin());
            time.erase(time.begin());
        }
        int t=0;
        for(int j=0;j<time.size();j++)t += time[j];
        if(t+q.front() <= weight) { // //weight보다 time모든합 (t)가 작을때만 push
            time.push_back(q.front());
            if (i!=1) index.push_back(i);
            q.pop();
        }
    }
    
    return answer;
}

int main(int argc, const char *argv[])
{

    int bridge_length, weight;
    vector<int> truck_weights;
    
    bridge_length = 2;
    weight = 10;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);

//    truck_weights.push_back(1);
//    truck_weights.push_back(1);
//    truck_weights.push_back(1);
//    truck_weights.push_back(1);
//    truck_weights.push_back(1);
//    truck_weights.push_back(2);
//    truck_weights.push_back(2);
//
//    bridge_length = 5;
//    weight = 5;
    

    solution(bridge_length,weight, truck_weights);
    
    return 0;
}

```
