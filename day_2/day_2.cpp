#include <iostream>
#include <fstream>
#include <string.h>


int get_strategy_score(std::ifstream &input_file)
{
    std::string line;

    int tot_score = 0;

    if (input_file.is_open())
    {
        while (std::getline(input_file, line)) 
        {
            if (line.length() == 3)
            {
                switch(line[2])
                {
                    case 'X':
                        tot_score += 1;

                        if (line[0] == 'A')
                            tot_score += 3;
                        if (line[0] == 'C')
                            tot_score += 6;

                        break;
                    
                    case 'Y':
                        tot_score += 2;

                        if (line[0] == 'A')
                            tot_score += 6;
                        if (line[0] == 'B')
                            tot_score += 3;

                        break;
                    
                    case 'Z':
                        tot_score += 3;

                        if (line[0] == 'B')
                            tot_score += 6;
                        if (line[0] == 'C')
                            tot_score += 3;

                        break;
                }
            }
        }
    }

    return tot_score;
}

int get_strategy_score_2(std::ifstream &input_file)
{
    std::string line;

    int tot_score = 0;

    if (input_file.is_open())
    {
        while (std::getline(input_file, line)) 
        {
            if (line.length() == 3)
            {
                switch(line[2])
                {
                    case 'X':
                        if (line[0] == 'A')
                            tot_score += 3;
                        if (line[0] == 'B')
                            tot_score += 1;
                        if (line[0] == 'C')
                            tot_score += 2;

                        break;
                    
                    case 'Y':
                        tot_score += 3;

                        if (line[0] == 'A')
                            tot_score += 1;
                        if (line[0] == 'B')
                            tot_score += 2;
                        if (line[0] == 'C')
                            tot_score += 3;

                        break;
                    
                    case 'Z':
                        tot_score += 6;
                        
                        if (line[0] == 'A')
                            tot_score += 2;
                        if (line[0] == 'B')
                            tot_score += 3;
                        if (line[0] == 'C')
                            tot_score += 1;

                        break;
                }
            }
        }
    }

    return tot_score;
}

int main()
{
    std::ifstream input_file;

    input_file.open("input");
    if(!input_file) { // file couldn't be opened
      std::cerr << "Error: file could not be opened" << std::endl;
      exit(1);
    }

    int strategy_score = get_strategy_score(input_file);  // First half

    // Reset the stream to the beginning
    input_file.clear();
    input_file.seekg (0);

    int strategy_score_2 = get_strategy_score_2(input_file); // Second half

    std::cout << "Final score: " << strategy_score << std::endl;
    std::cout << "Final score: " << strategy_score_2 << std::endl;
}