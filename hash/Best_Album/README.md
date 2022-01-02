# 해시 - 베스트앨범

##
genres_plays를 unordered_map으로 선언해서 장르, 플레이횟수, 고유번호 순서대로 저장한다.  
hash에는 해당 카테고리에 해당하는 플레이횟수만 더한다.  
genres_plays를 plays가 큰 순서대로 내림차순 정렬한다.  
hash는 unordered_map의 <string, int>로 선언했으므로 정렬이 불가능하다, hash_v 벡터를 선언하여 hash값들을 복사하고,  
hash_v를 플레이횟수가 큰것부터 내림차순 정렬한다.  
`genres_plays[hash_v[i].first][j].second` 는, hash_v벡터가 플레이횟수 큰것부터 정렬되어있으므로, i=0부터 장르개수만큼 순서대로, `j<2` 이면서 만약 장르하나에 요소가 한개라면 한개만 출력하도록 `j < genres_plays[hash_v[i].first].size()`  
해주고, 고유번호를 순서대로 answer벡터에 저장했다.


### 코드

```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
bool compare_v(pair<string,int> a,pair<string,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector< pair<int,int>>> genres_plays;
    unordered_map<string, int> hash;
    vector <pair<string,int>> hash_v;
    
    for(int i=0;i<genres.size();i++){
        genres_plays[genres[i]].push_back(make_pair(plays[i], i));
        hash[genres[i]] += plays[i];
    }
    
    for(auto &p : genres_plays){
        sort(p.second.begin(), p.second.end(), compare); //내림차순 정렬
    }
    
    hash_v.assign(hash.begin(),hash.end());
    sort(hash_v.begin(), hash_v.end(), compare_v); //hash_v 내림차순 정렬
    
    for(int i=0;i<hash_v.size();i++){
        for(int j=0; j<2 && j < genres_plays[hash_v[i].first].size(); j++){
            answer.push_back(genres_plays[hash_v[i].first][j].second);
        }
    }
    
    return answer;
}

int main(int argc, const char *argv[])
{

    vector<string> genres;
    vector<int> plays;
    vector<int> answer;

    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");
    
    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);
    
    
    answer = solution(genres, plays);
    
    return 0;
}


```
