#include "scanner.h"
#include "token.h"
#include <iostream>
#include <fstream>

// g++ -Wall -Werror -std=c++17 -g main.cpp -o lab1

int main (int argc, char* argv[]) {
    //ifstream f(argv[1]);
    ifstream f;
    f.open(argv[1]);
//    f.open("C:\\Users\\zacco\\Documents\\Coding\\CS236Project1\\tests\\project1-passoff\\20\\input23.txt");
//    stringstream buffer;
//    cout << "stop";
//    buffer << f.rdbuf();
//    string input = buffer.str();
    string content((istreambuf_iterator<char>(f)), (istreambuf_iterator<char>()));

    Scanner s = Scanner(content);
    Token t = s.scanToken();
    cout << t.toString() << endl;
    return 0;
}