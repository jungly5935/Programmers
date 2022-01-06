# 힙 - 디스크 컨트롤러

##
1. job벡터를 만들어서, 두번째 인덱스 [0],[1],[2],[3]에 각각 (요청시간, 작업시간, 시작시간, 종료시간)을 저장한다.  
2. 요청시간과 작업시간은 문제에서 주어져있고, 시작시간은 요청시간으로, 종료시간은 요청시간+작업시간으로 초기화해둔다.  
3. job벡터의 시작시간을 비교하여 오름차순으로 정리한다. 시작시간이 같은경우에는 종료시간을 기준으로 오름차순으로 정리한다.  
4. 맨 앞에있는 요소에 대해 각 작업 요청부터 종료까지 시간은 (종료시간 - 요청시간)이다. 이것의 평균을 구하는것이므로 누적합을 구한다.  
5. pop하기 직전의 종료시간보다 현재 들어오는 작업의 요청시간이 더 작은경우에는, 시작시간을 직전 종료시간으로, 종료시간을 (작업시간+시작시간)으로 수정한다.  
3~5번을 반복하면 전체 작업 요청부터 종료까지 시간을 구할 수 있는데, 평균을 구해야하므로 jobs.size()로 나눠준다.  


### 코드

```c++
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int>b){
    
    if(a[2] == b[2])return a[3]<b[3];
    else return a[2]<b[2];
   
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int end = 0;
    vector<vector<int>> job(jobs.begin(), jobs.end());
    
    for(int i=0;i<jobs.size();i++){
        job[i].push_back(jobs[i][0]);
        job[i].push_back(jobs[i][0]+jobs[i][1]);
    }
    
    while(!job.empty()){
        sort(job.begin(), job.end(), compare);
        //맨 앞 종료시간과 pop 후 시작시간 비교
        end = job[0][3];
        time += job[0][3] - job[0][0];
        job.erase(job.begin());
        
        for(int i=0;i<job.size();i++){
            if(end > job[i][0]){
                job[i][2] = end;
                job[i][3] = job[i][1]+job[i][2];
            }
          
        }
    }
    answer = time/jobs.size();
      return answer;
}

int main(int argc, const char *argv[])
{
    vector<vector<int>> jobs;
    
    vector<int> a,b,c,d,e;
//    a.push_back(0);
//    a.push_back(3);
//    b.push_back(1);
//    b.push_back(9);
//    c.push_back(2);
//    c.push_back(6);
    
//    a.push_back(0);
//    a.push_back(5);
//    b.push_back(2);
//    b.push_back(10);
//    c.push_back(10000);
//    c.push_back(2);
    
//    a.push_back(0);
//    a.push_back(3);
//    b.push_back(3);
//    b.push_back(9);
//    c.push_back(2);
//    c.push_back(11);
    
    a.push_back(1);
    a.push_back(9);
    b.push_back(1);
    b.push_back(4);
    c.push_back(1);
    c.push_back(5);
    d.push_back(1);
    d.push_back(7);
    e.push_back(1);
    e.push_back(3);
   
    jobs.push_back(a);
    jobs.push_back(b);
    jobs.push_back(c);
    jobs.push_back(d);
    jobs.push_back(e);
    
    solution(jobs);
    
    return 0;
}
```
