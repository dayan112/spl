#pragma once
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>


class FileHandler{
    public:
        FileHandler(const std::string path);  

        void FileToWordsMatrix();

        std::string& getContent();
        std::vector<std::vector<std::string>>& getWords();
    
    private:
        const std::string _path;
        std::string _content;
        int _num_of_lines;
        std::vector<std::vector<std::string>> _words;

        void FileToString();//this is the only place that opens files
        //string handle functions:
        std::vector<std::string> getLines();
        std::vector<std::string> lineToWord(const std::string& str);
        
        int countChar(const std::string& str, char c);
};
