#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#if 0
// opening file for write
std::fstream outFile {"text.txt", std::ios::out};
//or
std::fstream outFile;
outFile.open("text.txt", std::ios::out);
// or open for write binary
outFile.open("text.bin", std::ios::out | std::ios::binary); 

//the same

// opening file for write
std::ofstream outFile {"text.txt", std::ios::out};
//or
std::ofstream outFile;
outFile.open("text.txt");
// or open for write binary
outFile.open("text.bin", std::ios::binary);

// truncate (discard content) when opening (DEFAULT)
std::ofstream outFile {"text.txt", std::ios::trunc};

// append (to the end) when opening
std::ofstream outFile {"text.txt", std::ios::app};

// set initial position to the end of the file when opening
std::ofstream outFile {"text.txt", std::ios::ate};

// always close the file
outFile.close();

// writing to file:
int num {100};
float total {45.78};
std::string name {"Frank"}; 

outFile 
    << num << "\n"
    << total << "\n"
    << name << std::endl; // std::endl - flushes out any unread buffers

//write by character
outFile.put(c);

#endif

int main() {
    std::ofstream outFile{"out_file.txt", std::ios::app};
    std::string str{""};

    std::cout << "Enter string to write in file" << std::endl;
    std::getline(std::cin, str);
    std::cout << "str: " << str << std::endl;

    if (!outFile) {
        std::cerr << "File not opened!" << std::endl;
    } else {
        outFile << str;
        outFile.close();
    }

    return 0;
}