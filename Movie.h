/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-13

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds {
  class Movie {
    std::string m_title{};
    size_t m_year = 0;
    std::string m_description{};
  public:
    Movie(){};

    // a query function that returns the title of the movie
    const std::string& title() const;

    // a constructor that receives a reference to an unmodifiable string and 
    // extracts the movie information from the string
    Movie(const std::string& strMovie);

    // a function to display the movie information
    std::ostream& display(std::ostream& os) const;

    // a templated function with type T and must have an overload of the operator() 
    // that accepts a string as a parameter
    template<typename T>
    void fixSpelling(T& spellChecker) {
      spellChecker(m_title);
      spellChecker(m_description);
    };
    
    // a function to remove the trailing and leading spaces from a string and return the string without spaces
    std::string& removeSpaces(std::string &str);
  };

  // a helper operator to insert the content of a movie object into the output stream
  std::ostream& operator<<(std::ostream& os, const Movie& src);
}

#endif