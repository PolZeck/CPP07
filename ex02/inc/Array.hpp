/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:49:51 by pledieu           #+#    #+#             */
/*   Updated: 2026/01/19 09:50:01 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
    T* _elements; // Pointer to the dynamically allocated array
    unsigned int    _n;        // Number of elements in the array

public:
    /**
     * @brief Default constructor: Creates an empty array[cite: 207].
     */
    Array() : _elements(NULL), _n(0) {}

    /**
     * @brief Constructor with size n: Creates n elements initialized by default[cite: 208].
     * Using () with new T[n]() ensures value-initialization[cite: 209, 211].
     */
    Array(unsigned int n) : _n(n) {
        _elements = new T[n](); 
    }

    /**
     * @brief Copy constructor: Ensures deep copy.
     */
    Array(Array const & src) : _elements(NULL), _n(0) {
        *this = src;
    }

    /**
     * @brief Destructor: Must clean up allocated memory[cite: 48].
     */
    ~Array() {
        if (this->_elements)
            delete[] this->_elements;
    }

    /**
     * @brief Assignment operator: Handles memory cleanup and deep copy[cite: 49, 212].
     */
    Array & operator=(Array const & rhs) {
        if (this != &rhs) {
            if (this->_elements)
                delete[] this->_elements;
            this->_n = rhs._n;
            if (this->_n > 0) {
                this->_elements = new T[this->_n];
                for (unsigned int i = 0; i < this->_n; i++)
                    this->_elements[i] = rhs._elements[i];
            } else {
                this->_elements = NULL;
            }
        }
        return *this;
    }

    /**
     * @brief Subscript operator: Provides access with bounds checking[cite: 215, 217].
     * Throws std::exception if index is out of bounds.
     */
    T & operator[](unsigned int index) {
        if (index >= _n)
            throw OutOfBoundsException();
        return _elements[index];
    }

    /**
     * @brief Const subscript operator: For read-only access to constant arrays.
     */
    T const & operator[](unsigned int index) const {
        if (index >= _n)
            throw OutOfBoundsException();
        return _elements[index];
    }

    /**
     * @brief Member function size: Returns the number of elements[cite: 218].
     */
    unsigned int size() const {
        return _n;
    }

    /**
     * @brief Exception class for out of bounds access.
     */
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: Index out of bounds";
        }
    };
};

#endif