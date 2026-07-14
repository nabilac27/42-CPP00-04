/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:23:39 by nchairun          #+#    #+#             */
/*   Updated: 2025/10/28 23:12:36 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    int i, j;
    
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
        return(0);
    }

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            char c = argv[i][j];
            if (c >= 'a' && c <= 'z')
                c -= 32;
            std::cout << c;
            j++;
        }
        i++;
    }
    std::cout << std::endl;

    return (0);
}

/*
 <iostream>:
   - Input/output library in C++.
   - Provides:
     * std::cin → standard input (keyboard)
     * std::cout → standard output (console)
     * std::cerr → standard error output

 std::cout and <<:
   - std::cout is the object used to print output to the console.
   - << is the insertion operator; it "inserts" data into the output stream.

 std::endl:
   - A manipulator that inserts a newline and flushes the output buffer.

 std::
   - std is the standard namespace in C++ containing library functions, classes, and objects.
   - std:: tells the compiler to look inside the std namespace.

 namespace:
   - A container (or folder) for identifiers (variables, functions, classes) to avoid name conflicts.
   - Use the scope resolution operator :: to access names inside a namespace.
   - Example: std::cout accesses cout inside the standard namespace std.

 Character conversion:
   - c -= 32 converts lowercase letters ('a'-'z') to uppercase ('A'-'Z') using ASCII values.

 Endl: “end line”
  - Insert a newline (move to the next line)
  - Flush the output buffer (force everything in memory to display immediately)
*/