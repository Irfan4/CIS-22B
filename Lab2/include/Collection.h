#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;


class Collection
{
    private:
        struct Book // Data structure
        {
            string title;
            string author;
            string genre;
        };
        std::vector<Book> books; // Declare vector

    public:
        Collection() { // User defined constructor

        Book myBook; // Create structure variable

        std::string line; // Used for reading lines
        std::string defaultPath = "D:/Library/Books.txt";
        std::ifstream openBook (defaultPath.c_str()); // File handler
        std::string filePath;  // Represents user's inputted directory if defaultPath fails
        bool check = false;  //Used to initiate a second file opening after user input has been accepted

                while (!openBook.is_open()) {

                std::cout << "Failed to open. Please enter a new path to find the file: " << std::endl;
                getline (std::cin, filePath);
                std::ifstream openBook (filePath.c_str()); //Attempts to open file with user inputted directory

                if (openBook.is_open())
                {
                    defaultPath = filePath; //Swaps the default path with the accepted user inputted path
                    check = true; //check changes to true to satisfy if statement
                    break; //Exits while loop to continue with file reading
                }
            }

        if (check == true) { // For successful opening
           openBook.open(defaultPath.c_str());
        }

        if (openBook.is_open()) {

           while (getline(openBook, line))  { // Reading title, author, and genre in a loop
                    std::stringstream lineStream(line);
                    getline(lineStream, myBook.title, ',');
                    getline(lineStream, myBook.author, ',');
                    getline(lineStream, myBook.genre);
                    books.push_back(myBook); // Push into vector
           }

        }
            openBook.close(); // Closes file handler
    }

          void sortByTitle() // Title sorting function
          {
            std::sort(books.begin(), books.end(), [](Book b1, Book b2) { return b1.title < b2.title; });
          }

          void sortByAuthor() // Author sorting function
          {
            std::sort(books.begin(), books.end(), [](Book b1, Book b2) { return b1.author < b2.author; });
          }

          void sortByGenre() // Genre sorting function
          {
            std::sort(books.begin(), books.end(), [](Book b1, Book b2) { return b1.genre < b2.genre; });
          }

          void printFunction() // Print output
          {
            std::cout << left << setw(41) << "Title" << left << setw(36) << "Author" << left // Output header
                 << setw(50) << "Genre" << std::endl;

            for(Book val: books) // Prints output table
            {
                    std::cout << left << setw(40) << val.title << left << setw(36) << val.author
                         << left <<  setw(30) << val.genre << std::endl;
            }
          }

};

#endif // COLLECTION_H
