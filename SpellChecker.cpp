/* 
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-13

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include "SpellChecker.h"
#include <fstream>
#include <iomanip>

using namespace std;

namespace sdds {
  SpellChecker::SpellChecker(const char* filename) {
    ifstream file(filename);

    // check if file is open and throw an exception if it is not
    if (file) {
      for (auto i = 0u; i < numOfWords; i++) {
        size_t j = 0;

        string word{};
        getline(file, word);
        
        while(word[j] != ' ') {
          m_badWords[i] += word[j];
          j++;
        }

        while(j < word.length()) {
          if(word[j] != ' ') {
            m_goodWords[i] += word[j];
          }
          j++;
        }
      }
    }
    else {
      throw "Bad file name!";
    }
  }

  void SpellChecker::operator()(string& text) {
    // loop through the bad words
    for (size_t i = 0; i < numOfWords; i++) {
      size_t found = 0;

      while (found < text.length()) {
        // find the bad word in the text
        found = text.find(m_badWords[i], found);

        // check if the bad word is found
        if (found <= text.length()) {
          // replace the bad word with the good word
          text.replace(found, m_badWords[i].length(), m_goodWords[i]);
          m_replaceCount[i]++;
        }
      }
    }
  }

  void SpellChecker::showStatistics(ostream& os) const {
    // print the header
    os << "Spellchecker Statistics" << endl;

    // loop through the bad words
    for (size_t i = 0; i < numOfWords; i++) {
      os << setw(15) << right << m_badWords[i] << ": " << m_replaceCount[i] << " replacements" << endl;
    }
  }

  std::string& SpellChecker::removeSpaces(string& str) {
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
}