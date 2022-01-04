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
