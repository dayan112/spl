#include <iostream>
#include "../include/WareHouse.h"
#include "../include/FileHandler.h"
#include "../include/Global.h"

using namespace std;

WareHouse* backup = nullptr;

int main(int argc, char** argv){
    if(argc!=2){
        std::cout << "usage: warehouse <config_path>" << std::endl;
        return 0;
    }
    string configurationFile = argv[1];
    WareHouse wareHouse(configurationFile);

    wareHouse.open();
    wareHouse.start();
    
    if(backup!=nullptr){
    	delete backup;
    	backup = nullptr;
    }
    
    return 0;
}