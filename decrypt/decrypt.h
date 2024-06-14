#ifndef DECRYPT_H
#define DECRYPT_H
#include <fstream>

std::string descrambler(std::string hold);
void decryptEngine(std::ifstream &infile, std::ofstream &outfile);

#endif
