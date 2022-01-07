# 힙 - 이중우선순위큐

##
I 숫자 : 큐에 주어진 숫자 삽입  
D 1 : 큐에서 최댓값 삭제  
D -1 : 큐에서 최솟값 삭제  
  
1. operations벡터에 [i][0]번째는 항상 I아니면 D이므로 char oper 변수에 넣어준다.  
2. [i][1]번째는 공백이므로 [i][2]번째부터 [i]의 크기까지 oper_num 문자열에 저장 후 stoi를 이용해 숫자로 변환한다.  
3. I일때는 해당 num을 삽입하고, D일때는 -1인지 1인지 판별 후,  
4. -1이면 제일 앞에있는(최솟값)을 지우고, 1이면 제일 뒤에있는(최댓값)을 지운다.  
5. 오름차순으로 정렬했으므로  q의 제일앞이 최솟값, 제일뒤가 최댓값이다.  
이를 반복하며 q가 비었을때는 초기화값 그대로 answer은 [0,0]이고, q가 비지 않았을때는 [최댓값, 최솟값] 순으로 출력한다.


### 코드

```c++
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

```
