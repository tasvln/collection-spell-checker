/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-13

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include "Movie.h"
#include <iomanip>

using namespace std;

namespace sdds {
  // a query function that returns the title of the movie
  const std::string& Movie::title() const {
    return m_title;
  }

  // a one-argument constructor that receives a reference to an unmodifiable string
  Movie::Movie(const std::string& strMovie) {
    string tempStr = strMovie;
    string tempTitle{};
    string tempYear{};
    string tempDescription{};

    // extract the title
    tempTitle = tempStr.substr(0, tempStr.find(','));
    tempTitle = removeSpaces(tempTitle);
    tempStr.erase(0, tempStr.find(',') + 1);
    m_title = tempTitle;

    // extract the year
    tempYear = tempStr.substr(0, tempStr.find(','));
    tempYear = removeSpaces(tempYear);
    tempStr.erase(0, tempStr.find(',') + 1);
    m_year = stoi(tempYear);

    // extract the description
    tempDescription = tempStr.substr(0, tempStr.find('\n'));
    tempDescription = removeSpaces(tempDescription);
    tempStr.erase(0, tempStr.find('\n') + 1);
    m_description = tempDescription;
  }

  std::ostream & Movie::display(std::ostream & os) const {
    os << setw(40) << right << m_title << " | ";
    os << setw(4) << m_year << " | ";
    os << m_description << endl;

    return os;
  }

  std::string& Movie::removeSpaces(string& str) {
    // first loop till the first non space character and remove the spaces
    while (str[0] == ' ') {
      // remove the space from the string
      str.erase(0, 1);
    }

    // second loop till the last non space character and remove the spaces
    while (str[str.length() - 1] == ' ') {
      // remove the space from the string
      str.erase(str.length() - 1, 1);
    }

    return str;
  }

  std::ostream& operator<<(std::ostream& os, const Movie& src) {
    return src.display(os);
  }
}