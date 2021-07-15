#ifndef MIMUTIL_H
#define MIMUTIL_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


class Tokenizer:public vector<string> {
public:
  void getTokens(const string &str, const string &sep);
  int  getIndex(string str);
};

#endif
