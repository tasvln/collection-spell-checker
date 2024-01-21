/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-13

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

namespace sdds {
  const size_t numOfWords = 6;

  class SpellChecker {
    std::string m_badWords[numOfWords]{};
    std::string m_goodWords[numOfWords]{};
    size_t m_replaceCount[numOfWords]{};
  public:
    SpellChecker(){};
    // receives the address of a C-style null-terminated string and throws an exception of type const char* 
    SpellChecker(const char* filename);

    // a function that searches text and replaces any misspelled word with the correct version
    void operator()(std::string& text);

    // a function that shows how many times each misspelled word has been replaced
    void showStatistics(std::ostream& out) const;

    std::string& removeSpaces(std::string& str);
  };
}

#endif