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
