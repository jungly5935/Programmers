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
    //내림차순 정렬
    
    for(auto &p : genres_plays){
        sort(p.second.begin(), p.second.end(), compare);
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

