/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:30:19 by nchairun          #+#    #+#             */
/*   Updated: 2026/03/12 21:13:28 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void printMessage(const std::string &message)
{
    std::cerr << message << "\033[0m";
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printMessage("Usage: ./sed <filename> <s1> <s2>");
        return (EXIT_FAILURE);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        printMessage("s1 can't be empty");
        return(EXIT_FAILURE);
    }

    /* ********** */

    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        printMessage("Error: Invalid input file");
        return (EXIT_FAILURE);
    }

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open())
    {
        printMessage("Error: Invalid output file");
        inputFile.close();
        return (EXIT_FAILURE);
    }

    /* ********** */
    
    std::string line;

    while (std::getline(inputFile, line))
    {
        size_t index = 0;
    
        while (index < line.length())
        {
            index = line.find(s1, index);
            if (index >= line.length())
                break;
            line.erase(index, s1.length());
            line.insert(index, s2);
            index += s2.length();
        }
        outputFile << line << std::endl;
    }
    
    inputFile.close(); 
    outputFile.close();

    return (EXIT_SUCCESS);
}


/* ++++++++++++++++++++++++++++ */

// void printMessage(const std::string &message)
// {
//     std::cerr << message << "\033[0m";
// }


// int main(int argc, char **argv)
// {
//     if (argc != 4)
//     {
//         printMessage("Usage: ./sed <filename> <s1> <s2>");
//         return (1);
//     }

//     std::string filename = argv[1];
//     std::string s1 = argv[2];
//     std::string s2 = argv[3];

//     if (s1.empty())
//     {
//         printMessage("s1 can't be empty");
//         return (1);
//     }

//     /* ********** */

//     std::ifstream inputFile(filename.c_str());
//     if (!inputFile.is_open())
//     {
//         printMessage("Error: Invalid input file");
//         return (1);
//     }

//     std::ofstream outputFile((filename + ".replace").c_str());
//     if (!outputFile.is_open())
//     {
//         printMessage("Error: Invalid output file");
//         inputFile.close();
//         return (1);
//     }

//     /* ********** */

//     std::string line;

//     while (std::getline(inputFile, line))
//     {
//         size_t index = 0;

//         while (index < line.length())
//         {
//             index = line.find(s1, index);
//             if (index >= line.length())
//                 break;
//             line.erase(index, s1.length());
//             line.insert(index, s2);
//             index += s2.length();
//         }
//         outputFile << line << std::endl;
//     }

//     inputFile.close();
//     outputFile.close();

//     return (0);
// }
