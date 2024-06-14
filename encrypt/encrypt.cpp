#include <fstream>
#include <random>
#include "encrypt.h"

// encryption will be ascii + a randomised number with the randomised number changing after every space

void encryptEngine(std::ifstream &infile, std::ofstream &outfile){
    std::string line {};               
    std::random_device rd;
    std::uniform_int_distribution<int> dist(10, 99);  // creating a randomised number for the start of the program so that the first characters are not ignored
    int random = dist(rd);

    while(std::getline(infile, line)){
        
        for(char a : line){
            if(isspace(a)){            // check for spaces to put a tag for the decrypter to understand and to re randomise
                outfile << random << a;
                random = dist(rd);
                
            }else {

                int temp{0};
                if(random == 94) random = random - 20;
                temp = int(a) + random;      // changing ascii values within a range and looping back to the start if out of it
            
                if(temp > 126){
                    temp = (temp - 126) + 32;
                }
                
                outfile << char(temp);
            }
        }
        
        outfile << random << '\n';
        random = dist(rd);      // reusing random here for new line re-randomization.
    }
    
}
