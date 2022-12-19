#include <iostream>
#include <fstream>
#include <string.h>

double max_calories(std::ifstream &input_file){
    std::string line;
    
    double tot_elf = 0;
    double local_max = 0;

    if (input_file.is_open())
    {
        while (input_file)
        {
            
            std::getline (input_file, line);
            if (strcmp(line.c_str(), "") != 0)
            {
                tot_elf += atoi(line.c_str());
            } else 
            {
                if (local_max < tot_elf)
                {
                    local_max = tot_elf;
                }
                tot_elf = 0;
            }
        }
    }

    return local_max;
}

double top_three_calories(std::ifstream &input_file){
    std::string line;
    
    double tot_elf = 0;
    double tot_sum = 0;
    double top_three[3] = {0,0,0};
    double i;

    if (input_file.is_open())
    {
        
        while (input_file)
        {
            std::getline (input_file, line);
            if (strcmp(line.c_str(), "") != 0)
            {
                tot_elf += atoi(line.c_str());
            } else 
            {
                if (tot_elf > top_three[0])
                {
                    top_three[2] = top_three[1];
                    top_three[1] = top_three[0];
                    top_three[0] = tot_elf;
                } else if (tot_elf > top_three[1])
                {
                    top_three[2] = top_three[1];
                    top_three[1] = tot_elf;
                } else if (tot_elf > top_three[2])
                {
                    top_three[2] = tot_elf;
                }

                tot_elf = 0;                           
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        tot_sum += top_three[i];
    }

    return tot_sum;
}


int main () 
{
    std::ifstream input_file;

    input_file.open("input");
    if(!input_file) { // file couldn't be opened
      std::cerr << "Error: file could not be opened" << std::endl;
      exit(1);
   }

    double imax = max_calories(input_file);  // First half 

    // Reset the stream to the beginning
    input_file.clear();
    input_file.seekg (0);

    double top_three = top_three_calories(input_file);  // Second half
    
    std::cout << "Most calories: " << imax << std::endl;
    std::cout << "Top Three: " << top_three << std::endl;
}