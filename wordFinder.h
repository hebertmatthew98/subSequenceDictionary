#include <iostream>

#ifndef WORDFINDER_H
#define WORDFINDER_H
class wordFinder
{
    public:
        wordFinder(std::string);
        ~wordFinder();

    private:
		std::string dictionary[5] = {"able", "ale", "apple", "bale", "kangaroo"};
        
        bool runScan(std::string, int);
        void sortDictionary();
        bool trueSubSeq;

};
#endif