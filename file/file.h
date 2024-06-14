#ifndef FILE_H
#define FILE_H

#include <fstream>
std::string getFileName();
std::ifstream openFile(std::string filename);
std::ofstream createFile(std::string filename, bool opt);
bool choseOption();

#endif
