/**
 * \author Andy Hameed | 400073469
 *  \file Exceptions.h
 */


#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class invalid_move : public std::exception {
   const char * what () const throw () {
      return "Move is not valid!";
   }
};

class full : public std::exception {
   const char * what () const throw () {
      return "Pile is full!";
   }
};
 class not_available : public std::exception {
   const char * what () const throw () {
      return "Not available!";
   }
};

#endif