#include <iostream>
#include <fstream>
#include <string.h>

int main () 
{
    std::ifstream myfile;

    myfile.open("input");
    if(!myfile) { // file couldn't be opened
      std::cerr << "Error: file could not be opened" << std::endl;
      exit(1);
   }

    double imax = 0;
    double totalelf = 0;
    const char* new_line = "";

    std::string line;
    

    if (myfile.is_open())
    {
        while (myfile)
        {
            
            std::getline (myfile, line);
            if (strcmp(line.c_str(), new_line) != 0)
            {
                totalelf += atoi(line.c_str());
            } else 
            {
                if (imax < totalelf)
                {
                    imax = totalelf;
                }
                totalelf = 0;
            }
        }
    }
    
    std::cout << "Most calories: " << imax << std::endl;
}