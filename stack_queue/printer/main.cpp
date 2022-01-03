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
