#pragma once
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>


class FileHandler{
    public:

        ReadFile() = delete;//cannot create an instance of this class

        //parameter types changeable
        static std::vector<std::vector<std::string>> FileToWordsMatrix(const std::string path);
    
    private:
        static const std::string FileToString(const std::string path);//thee only place that opens files
        static std::vector<std::string> splitString(const std::string& line, char c);
        static int countChar(const string& str, char c);


};
