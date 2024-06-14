#include <fstream>
#include <string>
#include "decrypt.h"

std::string descrambler(std::string hold) {
    std::string di = hold.substr(hold.length() - 2);   // getting the key from the string
    int dec = std::stoi(di);
    hold.erase(hold.end() - 2, hold.end());            // removing the key
    std::string res{""};
    
    for(char a : hold){
        int temp =int(a) - dec;                        // reversing the encryption
        if(temp < 33){
            temp = (temp + 126) - 32;
        }
        res += char(temp);
    }
    return res;
}


void decryptEngine(std::ifstream &infile, std::ofstream &outfile){
    std::string line{};
    std::string hold{};
    while(std::getline(infile, line)){
        for(char a : line){
            if(isspace(a)){                              // these loops are to get the lines and characters,
                outfile << descrambler(hold) << a;       // i put the code to descramble the letters into a seperate function since
                hold = "";                               // it needed to be used twice D:
                continue;
            }
            hold += a;
        }
        outfile << descrambler(hold) << '\n';
        hold = "";
    }

}
