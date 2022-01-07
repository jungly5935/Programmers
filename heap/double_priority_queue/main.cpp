#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0,0};
    int num;
    vector<int> q;
    
    for(int i=0;i<operations.size();i++){
        string oper_num;
       char oper = operations[i][0];
        for(int j=2;j<operations[i].size();j++){
            oper_num += operations[i][j];
        }
        num = stoi(oper_num);
        
        if(oper == 'I'){
            q.push_back(num);
        }
        else if(oper == 'D') {
            if(q.empty()) continue;
            if(num == -1) q.erase(q.begin());
            else q.erase(q.end()-1);
        }
        sort(q.begin(), q.end());
    }
    
    if(!q.empty()){
        answer[0] = q.back();
        answer[1] = q.front();
    }
    return answer;
}

int main(int argc, const char *argv[])
{
    vector<string> operations;
    
//    operations.push_back("I 16");
//    operations.push_back("D 1");
    
//    operations.push_back("I 7");
//    operations.push_back("I 5");
//    operations.push_back("I -5");
//    operations.push_back("D -1");
    
    operations.push_back("I -45");
    operations.push_back("I 653");
    operations.push_back("D 1");
    operations.push_back("I -642");
    operations.push_back("I 45");
    operations.push_back("I 97");
    operations.push_back("D 1");
    operations.push_back("D -1");
    operations.push_back("I 333");
    
    solution(operations);
    
    return 0;
}
