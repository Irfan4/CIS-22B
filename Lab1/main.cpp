
/*****************************************************************

  CIS 22B

  Lab1: This program will open a text file through a default file
        path, and ask the user to input a new path if a file is
        not found.  After the file is found, it will read the file
        line by line and store the book titles into a vector.
        It will sort the vector, and pass it off to a function to
        print it out.

  Author: Irfan Ahmad

  Date: 7-13-2019

******************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

std::string printResult (std::vector <string> titles);


/* main will open the text file, and ask the user for a new directory if failed.
   It will read all lines of the file, and store solely the titles in a newly
   declared vector.  Lastly, it will call to sort the vector and pass off the
   sorted vector to printFunction.
*/

int main()
{
    std::string line; // Used for reading lines
    std::string defaultPath = "D:/Library";
    std::ifstream openBook (defaultPath.c_str()); // File handler
    std::string filePath;  // Represents user's inputted directory if defaultPath fails
    bool check = false;  //Used to initiate a second file opening after user input has been accepted

            while (!openBook.is_open()) {

            std::cout << "Failed to open. Please enter a new path to find the file: " << std::endl;
            std::getline (std::cin, filePath);
            std::ifstream openBook (filePath.c_str()); //Attempts to open file with user inputted directory

            if (openBook.is_open())
            {
                defaultPath = filePath; //Swaps the default path with the accepted user inputted path
                check = true; //num changes to 1 to satisfy if statement
                break; //Exits while loop to continue with file reading
            }
        }

    if (check == true) { // For successful opening
       openBook.open(defaultPath.c_str());
    }

    std::vector <string> bookTitles;
    std::string title; // Represents solely the book titles

    if (openBook.is_open()) {

       while (getline(openBook, line))  // While reading, find the title and push it into the vector
        {
                std::stringstream lineStream(line);
                getline(lineStream,title,',');
                bookTitles.push_back(title);
        }
            std::sort(bookTitles.begin(), bookTitles.end());  // Sorts all titles alphabetically from first to last element
            cout << endl;

            printResult (bookTitles);

            openBook.close();  // Closes file handler
    }

    return 0;
}

/* printFunction will receive a sorted vector from main,
   and utilize a range based for loop to output all
   elements of the sorted vector.
*/

std::string printResult(vector <string> titles) {

           for(std::string val : titles)  // Range based for loop used to read all elements in the container (vector)
             std::cout << val << std::endl;
}

/* Output of program

Failed to open. Please enter a new path to find the file:
D:/Library/Books.txt

Ashes
Fall of Giants
Fundamentals of Database Systems
Mindset: The New Psychology of Success
One Hundred Years of Solitude
Replay
Starting out with c++
The C++ Programming Language
The Dark Forest
The Pillars of the Earth

Process returned 0 (0x0)   execution time : 7.599 s
Press any key to continue.


*/
