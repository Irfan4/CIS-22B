
/*****************************************************************

  CIS 22B

  Lab2: This program will take user choice on whether to sort
        the books by title, author, or genre. Once the choice
        is validated, it will read the file in a
        constructor and use the structure in private to push
        books into a vector. Lastly it will call the
        respective sorting function and afterwards the print
        function.

  Author: Irfan Ahmad

  Date: 7-20-2019

******************************************************************/


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Collection.h"

using namespace std;

int main() {

    int choice;

    std::cout << "Select which category you would like the books sorted by: " << std::endl
         << std::endl << "Sort by Title - Press 1"
         << std::endl << "Sort by Author - Press 2"
         << std::endl << "Sort by Genre - Press 3" << std::endl << std::endl;
    std::cin >> choice; // User input
    std::cout << std::endl;

    while (choice != 1 && choice != 2 && choice != 3) // Choice validation
    {
        std::cout << "Invalid choice. Enter again from the following: " // Repeat choices
             << std::endl << "Sort by Title - Press 1"
             << std::endl << "Sort by Author - Press 2"
             << std::endl << "Sort by Genre - Press 3"
             << std::endl << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
    }

    Collection myCollection; // Class instantiation

    if(choice == 1) { // Sort by title
        myCollection.sortByTitle();
    }
    else if(choice == 2) { // Sort by author
        myCollection.sortByAuthor();
    }
    else if (choice == 3) { // Sort by genre
        myCollection.sortByGenre();
    }
    else
        std::cout << "No valid input";

    myCollection.printFunction(); // Calling for print

    return 0;

}


/* Output of program:


Select which category you would like the books sorted by:

Sort by Title - Press 1
Sort by Author - Press 2
Sort by Genre - Press 3

7

Invalid choice. Enter again from the following:
Sort by Title - Press 1
Sort by Author - Press 2
Sort by Genre - Press 3

2

Title                                    Author                              Genre
The C++ Programming Language             Bjarne Stroustrup                   technical
Mindset: The New Psychology of Success   Carol Dweck                         psychology
Fundamentals of Database Systems         Elmarsi & Navathe                   technical
One Hundred Years of Solitude            Gabriel Garcia Marquez              fiction
Fall of Giants                           Ken Follet                          historical fiction
The Pillars of the Earth                 Ken Follett                         historical fiction
Replay                                   Ken Grimwood                        fantasy
Ashes                                    Kenzo Kitakana                      fiction
The Dark Forest                          Liu Cixin                           science fiction
Starting out with c++                    Tony Gaddis                         technical

Process returned 0 (0x0)   execution time : 4.412 s
Press any key to continue.
*/
