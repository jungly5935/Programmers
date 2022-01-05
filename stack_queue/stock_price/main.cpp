#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> time;

    for(int i=prices.size()-1;i>=0;i--) time.push_back(i);
    for(int i=0;i<time.size();i++){
        for(int j=i+1;j<time.size();j++){
            if(prices[i] > prices[j]) {
                time[i] =  j-i;
                break;
            }
        }
    }

    return time;
}

int main(int argc, const char *argv[])
{

    vector<int> prices;
  
//    prices.push_back(1);
//    prices.push_back(2);
//    prices.push_back(3);
//    prices.push_back(2);
//    prices.push_back(3);
//
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(1);
    
    solution(prices);
    
    return 0;
}
