#pragma once

#include "token.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Scanner {
private:
  string input;

public:
  Scanner(const string &input) : input(input) {}

  Token scanToken() {
      int lineAt = 0;
    while (isspace(input.at(0))) {
      input = input.substr(1);
    }
    if (input.at(0) == '\n') {
        lineAt++;
    }
    if (input.at(0) == ',') {
      input = input.substr(1);
      return Token(COMMA, ",", lineAt);
    }
		else if (input.at(0) == '.') {
			input = input.substr(1);
      return Token(PERIOD, ".", lineAt);
		}
		else if (input.at(0) == '?') {
			input = input.substr(1);
      return Token(Q_MARK, "?", lineAt);
		}
		else if (input.at(0) == '(') {
			input = input.substr(1);
      return Token(LEFT_PAREN, "(", lineAt);
		}
		else if (input.at(0) == ')') {
			input = input.substr(1);
      return Token(RIGHT_PAREN, ")", lineAt);
		}
		else if (input.at(0) == ':') {
			if(input.at(1) == '-') {
				input = input.substr(2);
	      return Token(COLON_DASH, ":-", lineAt);
			} 
			else {
				input = input.substr(1);
      	return Token(COLON, ":", lineAt);
			}
		}
		else if (input.at(0) == '*') {
			input = input.substr(1);
      return Token(MULTIPLY, "*", lineAt);
		}
		else if (input.at(0) == '+') {
			input = input.substr(1);
      return Token(ADD, "+", lineAt);
		}
		// SCHEMES,FACTS,RULES,QUERIES,ID,STRING,COMMENT,UNDEFINED,END
        // String tests from " to " and consumes everything inside
        // Comment tests from # to new line and consumes everything inside
        // All the rest wait for the next space then test to see which it
            // is, if its none of them it's an id
        else if (input.at(0) == '#') {
            int pos = 0;
            string commentString = "";
            while (input.at(pos) != '\n') {
                //append input.at(pos) to string
                commentString.push_back(input.at(pos));
                input = input.substr(pos + 1);
            }
        return Token(COMMENT, commentString, lineAt);
        }
		
		return Token(UNDEFINED, "NULL", lineAt);
  }

  vector<Token>;

};

