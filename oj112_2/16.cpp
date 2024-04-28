#include <iostream>
#include <cstring>
using namespace std;

class Anagram : public string {
public:
    string A = "";

    Anagram(string buf){
        char tmp;
        for(auto i=0;i<buf.size();i++){
            if(isalpha(buf[i])) A += tolower(buf[i]);
        }
        for(auto i=A.size()-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(A[j] > A[j+1]){
                    tmp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = tmp;
                }
            }
        }
    }
    bool operator==(const Anagram &str) const{
        int counts=0;
        for(auto i=0;i<A.size();i++){
            if(this->A[i] == str.A[i]) counts++;
        }
        if(counts == A.size()) return 1;
        return 0;
    }
};

int main() {
  string buf;
  getline(cin, buf);
  Anagram a1(buf);
  getline(cin, buf);
  Anagram a2(buf);
  cout << (a1 == a2) << endl;
  cout << (a2 == a1) << endl;
}
