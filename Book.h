/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-13

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds {
  class Book {
    std::string m_author{};
    std::string m_title{};
    std::string m_country{};
    size_t m_year = 0;
    double m_price = 0.0;
    std::string m_description{};
  public:
    // a default constructor
    Book(){};

    // a one-argument constructor that receives a reference to an unmodifiable string.
    Book(const std::string& strBook);

    // a function to return the title of the book
    const std::string& title() const;

    // a function to return the country of the book
    const std::string& country() const;

    // a function to return the year of the book
    const size_t& year() const;

    // a function to return the price of the book
    double& price();

    // a function to remove the trailing and leading spaces from a string and return the string without spaces
    std::string& removeSpaces(std::string &str);

    // a function to display the book information
    std::ostream& display(std::ostream &os) const;

    // a templated function with type T and must have an overload of the operator() 
    // that accepts a string as a parameter
    template<typename T>
    void fixSpelling(T& spellChecker) {
      spellChecker(m_description);
    };
  };

  // a helper operator to display the book information
  std::ostream& operator<<(std::ostream& os, const Book& src);
}

#endif