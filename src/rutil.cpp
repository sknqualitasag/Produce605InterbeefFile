#include "rutil.h"
using namespace std;

void Tokenizer::getTokens(const string &str, const string &sep){
  clear();
  string::size_type begidx,endidx;
  begidx = str.find_first_not_of(sep); //http://www.cplusplus.com/reference/string/string/find_first_not_of/
  while (begidx != string::npos) {
    endidx = str.find_first_of(sep,begidx);
    if (endidx == string::npos) endidx = str.length();
    push_back(str.substr(begidx,endidx - begidx));
    begidx = str.find_first_not_of(sep,endidx);
  }
}

int Tokenizer::getIndex(string str){
  for (unsigned i=0;i<size();i++){
    if((*this)[i]==str){
      return i;
    }
  }
  return -1;
}
