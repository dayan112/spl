#include<string.h>
#include<iostream>
#include<fstream>
#include"../include/FileHandler.h"

using namespace std;

static vector<vector<string>*>& FileHandler::FileToWordsMatrix(const string path){
    string content(FileToString(path));
    vector<string>* lines = FileHandler::splitString(content,'\n');
    
    vector<vector<string>*>* res = new vector<vector<string>>();
    
    for(int i = 0; i < lines.size(), i++){
        res->push_back(FileHandler::splitString(lines.at(i),' '));
    }

    vector<vector<string>*>& res_reference = *res;
    return res;
}

static const string FileHandler::FileToString(const std::string path){
    string content("");
    ifstream readFile(path);

    readFile >> content;

    readFile.close();
    return content;
}


static vector<string>* FileHandler::splitString(const string& str, char c){
    int vectorSize = FileHandler::countChar(str,c);
    string word("");
    vector<string>* res = new vector<string>(vectorSize);

    for(int i=0; i<str.length; i++){
        if(str[i] != c){
            word+=str[i];
        }
        else{
            res->push_back(word);
            word = "";
        }
    }

    return res;
}

static int FileHandler::countChar(const string& str, char c){
    int count = 0;
    string word("");

    for(int i=0; i<str.length; i++){
        if(str[i] == c){
            count++;
        }
    }

    return count;
}
 
