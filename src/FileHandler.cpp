#include<string.h>
#include<iostream>
#include<fstream>
#include"FileHandler.h"

using namespace std;

FileHandler::FileHandler(const std::string& path):_path(path),_num_of_lines(1){}

void FileHandler::FileToWordsMatrix(){
    FileToString();
    vector<string> temp;
    vector<string> lines = this->getLines();

    for(string str : lines){
        if(str == "") continue;
        _words.push_back(lineToWord(str));
    }
}

void FileHandler::FileToString(){
    ifstream readFile(_path);

    if(readFile.is_open()){
        char myChar;
        while(readFile){
            myChar = readFile.get();
            _content += myChar;
            if(myChar == '\n') _num_of_lines++;
        }
    }

    readFile.close();
}

vector<string> FileHandler::getLines(){
    //_content is not empty.
    string temp = "";
    bool isHashtaged = false;
    vector<string> res(_num_of_lines + 1);

    for(char c : _content){
        if(c == '\n'){
            if(temp != ""){
                res.push_back(temp);
                temp = "";
            }
            isHashtaged = false;
        }
        else if(isHashtaged){
            continue;
        }
        else if(c == '#'){
            isHashtaged = true;
        }
        else{
            temp += c;
        }
    }
    if(temp != ""){
        res.push_back(temp);
    }

    return res;
}

vector<string> FileHandler::lineToWord(const string& str){
    int vectorSize = FileHandler::countChar(str,' ');
    string temp("");
    vector<string> res(vectorSize);
    
    for(char c : str){
        if(c == ' '){
            if(temp != ""){
                res.push_back(temp);
                temp = "";
            }
        }
        else{
            temp += c;
        }
    }
    if(temp != ""){
        res.push_back(temp);
    }
    return res;
}

int FileHandler::countChar(const string& str, char c){
    int count = 0;
    string word("");

    for(int i=0; i<str.length(); i++){
        if(str[i] == c){
            count++;
        }
    }

    return count;
}
 
