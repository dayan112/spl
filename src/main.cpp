#include <iostream>
#include "../include/Order.h" 
#include "../include/Volunteer.h"
#include "../include/Customer.h"
#include"../include/FileHandler.h"
using namespace std;


int main(int argc, char** argv){

    FileHandler file("./configFileExample.txt");
    file.FileToWordsMatrix();
    vector<vector<string>> words = file.getWords();
    for(vector<string> line : words){
        for(string word : line){
            cout<<word<<"|";
        }
        cout << endl;
    }
    // Order myOrder(1, 123, 50); 
    // myOrder.setCollectorId(456); 
    // cout << "Order test:\n" << myOrder.toString() << endl;
        
    // SoldierCustomer dayan(1,"dayan",20,3);
    // cout << "Dayan mi? " << endl;



    return 0;
}