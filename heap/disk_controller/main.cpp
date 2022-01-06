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