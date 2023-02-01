#pragma once

// Complex string tokens

#include "token.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Scanner {
private:
    string input;
    int lineAt = 1;
    int pos = 0;

public:
  Scanner(const string &input) : input(input) {}

  Token scanToken() {
      if (input.empty()) {
          return {END, "", lineAt};
      }
      while (isspace(input.at(0))) {
        if (input.at(0) == '\n') {
            lineAt++;
        }
          input = input.substr(1);
          if (input.empty()) {
            return {END, "", lineAt};
        }
      }
    if (input.at(0) == ',') {
      input = input.substr(1);
      return {COMMA, ",", lineAt};
    }
    else if (input.at(0) == '.') {
	  input = input.substr(1);
      return {PERIOD, ".", lineAt};
    }
    else if (input.at(0) == '?') {
      input = input.substr(1);
      return {Q_MARK, "?", lineAt};
    }
    else if (input.at(0) == '(') {
      input = input.substr(1);
      return {LEFT_PAREN, "(", lineAt};
    }
    else if (input.at(0) == ')') {
      input = input.substr(1);
      return {RIGHT_PAREN, ")", lineAt};
    }
    else if (input.at(0) == ':') {
      if(input.at(1) == '-') {
        input = input.substr(2);
        return {COLON_DASH, ":-", lineAt};
    }
      else {
        input = input.substr(1);
        return {COLON, ":", lineAt};
      }
    }
    else if (input.at(0) == '*') {
      input = input.substr(1);
      return {MULTIPLY, "*", lineAt};
    }
    else if (input.at(0) == '+') {
      input = input.substr(1);
      return {ADD, "+", lineAt};
    }
    else if (input.at(0) == '#') {
        pos = 0;
        string commentString = "";
        while (input.at(pos) != '\n') {
            commentString.push_back(input.at(pos));
            input = input.substr(pos + 1);
        }
        return {COMMENT, commentString, lineAt};
    }
    else if (input.at(0) == '\'') {
        pos = 1;
        string stringString = "";
        while (input.at(pos) != '\'') {
            if (input.at(pos) == '\n') {
                lineAt++;
            }
            stringString.push_back(input.at(pos));
            pos = pos + 1;
        }
        input = input.substr(pos + 1);
        return {STRING, stringString, lineAt};
    }
        string v = input.substr(0, 1);
        input = input.substr(1);
    return {UNDEFINED, v, lineAt};

  }

  vector<Token> scanLoop() {
      vector<Token> vectorOfTokens;
      do {
          Token tmp = scanToken();
          vectorOfTokens.push_back(tmp);
      } while(input.length() != 0);
//      while(input.length() != 0) {
//          Token tmp = scanToken();
//          vectorOfTokens.push_back(tmp);
//      }
  return vectorOfTokens;
  }
};

//Token Scanner::consumeIdentifier(char start) {
//    char c = start;
//    string val;
//    val.push_back(c);
//
//    if (!isalpha(c)) {
//        return Token(UNDEFINED, val, lineAt);
//    }
//
//    c = input.at(0);
//    while (isalnum(c)) {
//        val.push_back(c);
//        input = input.substr(1);
//        c = input.at(0);
//    }
//
//    if (val == "Schemes") {
//        return Token(SCHEMES, val, lineAt);
//    }
//    if (val == "Facts") {
//        return Token(FACTS, val, lineAt);
//    }
//    if (val == "Rules") {
//        return Token(RULES, val, lineAt);
//    }
//    if (val == "Queries") {
//        return Token(QUERIES, val, lineAt);
//    }
//   return Token(ID, val, lineAt);
//}