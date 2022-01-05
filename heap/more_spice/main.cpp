#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int> ,greater<int>> q(scoville.begin(), scoville.end());

    while(q.top() < K && q.size() >= 2){

        int top = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        q.push(top + second*2);

        answer++;

    }
    if(q.size() < 2 && q.top() < K ) answer = -1;
    return answer;
}

int main(int argc, const char *argv[])
{

    vector<int> scoville;
    int K = 7;
//    scoville.push_back(1);
//    scoville.push_back(2);
//    scoville.push_back(3);
//    scoville.push_back(9);
//    scoville.push_back(10);
//    scoville.push_back(12);

    scoville.push_back(1);
    scoville.push_back(2);
    K=3;
    
    solution(scoville, K);
    
    return 0;
}
