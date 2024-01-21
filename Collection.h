/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-13

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>

namespace sdds {
  template <typename T>
  class Collection {
    std::string m_name{};
    T* m_items{};
    size_t m_size{};
    void (*m_observer)(const Collection<T>&, const T&){};
  public:
    // a default constructor that sets the object to a safe empty state and sets the name of the collection
    Collection(const std::string& name){
      m_name = name;
      m_items = nullptr;
      m_size = 0;
      m_observer = nullptr;
    };

    // prevents copying
    Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;
		Collection(const Collection&& src) = delete;
		Collection& operator=(const Collection&& src) = delete;

    // destructor
    ~Collection() {
      delete[] m_items;
    }

    // a query function that returns the name of the collection
    const std::string& name() const {
      return m_name;
    }

    // a query function that returns the number of items in the collection
    size_t size() const {
      return m_size;
    }

    void setObserver(void (*observer)(const Collection<T>&, const T&)) {
      m_observer = observer;
    }

    Collection<T>& operator+=(const T& item){
      bool found = false;

      // check if the item is already in the collection
      for (auto i = 0u; i < m_size; i++) {
        if (m_items[i].title() == item.title()) {
          found = true;
        }
      }

      // if the item is not in the collection, resize the array and add the item
      if (!found) {
        T* temp = new T[m_size + 1];

        for (auto i = 0u; i < m_size; i++) {
          temp[i] = m_items[i];
        }

        temp[m_size++] = item;

        // delete the old array and assign the new array to the old array
        delete[] m_items;
        m_items = temp;

        // if an observer has been registered, call the observer
        if (m_observer) {
          m_observer(*this, item);
        }
      }

      return *this;
    }

    // a query that returns the item at index of the m_items array and throws an exception if the index is out of bounds
    T& operator[](size_t id) const {
      if (id >= m_size) {
        throw std::out_of_range("Bad index [" + std::to_string(id) + "]. Collection has [" + std::to_string(m_size) + "] items.");
      }

      return m_items[id];
    }

    // a query that returns the address of the item with the title
    T* operator[](const std::string& title) const {
      T* item = nullptr;

      // check if the item is in the collection
      for (auto i = 0u; i < m_size; i++) {
        if (m_items[i].title() == title) {
          item = &m_items[i];
        }
      }

      return item;
    }
    
    // display function
    std::ostream& display(std::ostream& os) const {
      for(auto i = 0u; i < m_size; i++) {
        os << m_items[i];
      }

      return os;
    }
  };

  // helper function that inserts the name of the collection into the output stream
  template <typename T>
  std::ostream& operator<<(std::ostream& os, const Collection<T>& src){
    return src.display(os);
  }
}

#endif
