#include <iostream>
#include <fstream>
#include "file.h"

std::string getFileName(){

    std::cout << "Enter the name of the file you want to encrypt/decrypt(make sure to add .txt): " << '\n';    // asking for the file name
    std::string filename{};
    std::cin >> filename;
    return filename;
}

std::ifstream openFile(std::string filename){

    std::ifstream infile{filename};    // checking if the file is valid
    if(infile.is_open()){
        return infile;
    }
    std::cout << "invalid input!!" << '\n';
    exit(1);
}

std::ofstream createFile(std::string filename, bool opt){ 
    if(opt == true){
        std::ofstream outfile{"encrypted-" + filename};  // creating another text file for the encrypted/decrypted txt
        return outfile;
    }
    else if(opt == false){
        std::ofstream outfile{"decrypted-" + filename};
        return outfile;
    }
    
    std::cout << "Problem creating" << '\n';
    exit(3);
}

bool choseOption(){
    std::cout << "Would you like to decrypt or encrypt a text?" << '\n'
              << "Enter 1 for Encrypt." << '\n' 
              << "Enter 2 for Decrypt." << '\n';
    int input{0};
    std::cin >> input;
    if(input == 1 || input == 2){
        return input == 1;
    }

    std::cout << "Invalid option" << '\n';
    exit(2);
    
}
