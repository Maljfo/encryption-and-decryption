#include <fstream>
#include "file/file.h"
#include "encrypt/encrypt.h"
#include "decrypt/decrypt.h"

int main() {
    std::string name = getFileName();     // getting the name from the user
    bool opt = choseOption();
    std::ifstream infile = openFile(name);   // opening and checking the file to make sure it is valid
    std::ofstream outfile = createFile(name, opt);   // creating a file to pass the encrypted text over

    if(opt == true){
        encryptEngine(infile, outfile);  // encrypting the text from infile and putting it into the outfile
    } 
    else if(opt == false){
        decryptEngine(infile, outfile);  // decrypting text from infile and putting it into outfile
    }
    
    infile.close();
    outfile.close();

    return 0;
}
