# 해시 - 전화번호 목록

##
Programmers에서는 입력이 주어지므로 main에 임시 예제를 넣고 테스트했다.  
phone_book의 배열을 오름차순으로 정리한 뒤, 양 옆을 비교하여 하나라도 틀린게 있다면 true로,
접두어로 한 단어라도 겹치는게 있다면 false를 출력한다. false가 하나라도 있으면 바로 return을 해줘서 효율성을 높였다.


### 코드

```c++
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


```
