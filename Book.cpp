/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-13

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {
  Book::Book(const string& strBook) {
    string tempStr = strBook;
    string tempAuthor{};
    string tempTitle{};
    string tempCountry{};
    string tempYear{};
    string tempPrice{};
    string tempDesc{};

    // get the author
    tempAuthor = tempStr.substr(0, tempStr.find(','));

    // remove the trailing and leading spaces
    tempAuthor = removeSpaces(tempAuthor);

    // remove the author from the string
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the author
    m_author = tempAuthor;

    // get the title
    tempTitle = tempStr.substr(0, tempStr.find(','));
    tempTitle = removeSpaces(tempTitle);
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the title
    m_title = tempTitle;

    // get the country
    tempCountry = tempStr.substr(0, tempStr.find(','));
    tempCountry = removeSpaces(tempCountry);
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the country
    m_country = tempCountry;

    // get the price
    tempPrice = tempStr.substr(0, tempStr.find(','));
    tempPrice = removeSpaces(tempPrice);
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the price
    m_price = stod(tempPrice);

    // get the year
    tempYear = tempStr.substr(0, tempStr.find(','));
    tempYear = removeSpaces(tempYear);
    tempStr.erase(0, tempStr.find(',') + 1);

    // set the year
    m_year = stoi(tempYear);

    // get the description
    tempDesc = tempStr.substr(0, tempStr.find('\n'));
    tempDesc = removeSpaces(tempDesc);
    tempStr.erase(0, tempStr.find('\n') + 1);

    // set the description
    m_description = tempDesc;
  }

  const string& Book::title() const {
    return m_title;
  }

  const string& Book::country() const {
    return m_country;
  }

  const size_t& Book::year() const {
    return m_year;
  }

  double& Book::price() {
    return m_price;
  }

  std::string& Book::removeSpaces(string& str) {
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

  std::ostream& Book::display(std::ostream& os) const {
    os << setw(20) << right << m_author << " | ";
    os << setw(22) << right << m_title << " | ";
    os << setw(5) << right << m_country << " | ";
    os << setw(4) << m_year << " | ";
    os << setw(6) << fixed << setprecision(2) << m_price << " | ";
    os << left << m_description << endl;
    return os;
  }

  std::ostream& operator<<(std::ostream& os, const Book& src) {
    return src.display(os);
  }
}