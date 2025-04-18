#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "loveleetcode";
    int length = s.length();
    bool isRepeated = false;
    cout<<"String length = "<< length<<endl;
    for (int i = 0; i<length; i++){
      isRepeated = false;
      for (int j = 0; j < length; j++){
        if (i != j && s[i] == s[j]){
          isRepeated = true;
          break;
        }
      }
      if (isRepeated == false){
        cout << s[i];
      }
    }
    return 0;
}


