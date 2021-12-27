#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        bool flag = false;
       
        for(int j=0;j<phone_book[i].size();j++){
            if(phone_book[i][j] != phone_book[i+1][j]) flag = true; //[0]이아니라 접두어 한뭉치가 같아야 함.
        }
        if (flag == true) answer = true;
        
        else {
            answer = false;
            return answer;
        }
    }
    return answer;
}

int main(int argc, const char *argv[])
{
    vector<string> phone_book;
    
    phone_book.push_back("11");
    phone_book.push_back("12");
    phone_book.push_back("111");
//    phone_book.push_back("123223123");
//    phone_book.push_back("1231231234");
    
    bool answer = solution(phone_book);
    
    cout << answer;
    return 0;
}
