# 스택/큐 - 기능개발

##
rest 벡터는 (100-progress[i])으로 남은 작업 진도와, 그것을 speeds[i]로 나눈 값을 올림해서 저장한다.  
예시 progress = [93, 30, 55] / speeds = [1, 30, 5] 의 경우,  
7/1 , 70/30, 45/5 가 되는데, 70/30의경우 2.3333...으로 나누어떨어지지 않는다. 이런 경우 3으로 올림을해줘야 문제에서 말하는 배포일과 일치한다.  
process스택에는 rest배열에 저장된 값을 반대로 저장 후, process스택이 빌때까지  
1. 현재 process.top()의 수보다 그 다음오는 값이 더 작으면 p[i]값에 +1씩 더하고,  
2. 현재 process.top()의 수보다 그 다음오는 값이 더 클때 p벡터 요소를 하나 더 추가시킨다. 
1~2번을 반복한다.


### 코드

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<double> rest;
    stack<int> process;
    vector<int> p;
    
    for(int i=0;i<progresses.size();i++){
        rest.push_back(ceil(((100-progresses[i]))/ceil(speeds[i]))); // 7 3 9
    }
    for(int i=0;i<progresses.size();i++){
        process.push(rest[progresses.size() - i -1]);
    }
    
    int i=0;
    p.push_back(1);
    int t = process.top();
    process.pop();

    while(!process.empty()){
        
        if(t < process.top()) {
            p.push_back(1);
            t = process.top();
            i++;
        }
        else p[i]++;
    
        process.pop();
    }
    
    for(int i=0;i<p.size();i++)answer.push_back(p[i]);
    
    return answer;
}

int main(int argc, const char *argv[])
{

    vector<int> progresses;
    vector<int> speeds;
    
//    progresses.push_back(93);
//    progresses.push_back(30);
//    progresses.push_back(55);
//    speeds.push_back(1);
//    speeds.push_back(30);
//    speeds.push_back(5);
//
    progresses.push_back(95);
    progresses.push_back(90);
    progresses.push_back(99);
    progresses.push_back(99);
    progresses.push_back(80);
    progresses.push_back(99);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    
    solution(progresses, speeds);
    
    return 0;
}


```
