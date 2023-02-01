#pragma once

// Make undefined return the undefined char
// Complex string tokens
// EOF token doesn't read

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
//      char c = input.at(0);
      while (isspace(input.at(0))) {
        if (input.at(0) == '\n') {
            lineAt++;
        }
        input = input.substr(1);
        if (input.empty()) {
            return {END, "", lineAt};
        }
//            c = input.at(0);
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
		// SCHEMES,FACTS,RULES,QUERIES,ID
        // String tests from " to " and consumes everything inside
        // Comment tests from # to new line and consumes everything inside
        // All the rest wait for the next space then test to see which it
            // is, if its none of them it's an id

//    else if (input.at(0) == 'S') {
//        pos = 0;
//        string schemeString = "";
//        while (input.at(pos + 1) == "c") {
//            schemeString.push_back(input.at(pos));
//            input = input.substr(pos + 1);
//        }
//        return {SCHEMES, schemeString, lineAt};
//    }


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
        input = input.substr(1);
    return {UNDEFINED, "NULL", lineAt};

  }

  vector<Token> scanLoop() {
      vector<Token> vectorOfTokens;
      while(input.length() != 0) {

          Token tmp = scanToken();
          vectorOfTokens.push_back(tmp);
      }
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
//    if (val == "Schemes") {
//        return Token(SCHEMES, val, lineAt);
//    }
//        if (val == "Schemes") {
//        return Token(SCHEMES, val, lineAt);
//            if (val == "Schemes") {
//                return Token(SCHEMES, val, lineAt);
//}
//
