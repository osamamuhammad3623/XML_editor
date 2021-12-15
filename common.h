#ifndef COMMON_H_
#define COMMON_H_
#include <iostream>
#include <vector>
#include "QString"
using namespace std;

bool isOpeningTag(string row);

bool isClosingTag(string row);

bool isData(string row);

/*
 * Desc: A function that takes an XML string and returns a vector of strings, separating
 * 			xml data and tags into rows
 * */
vector<string> xmlStringToVector(string &text);


/*
 * Desc: A function to convert a vector of strings to a QString [used in displaying formatted text]
*/
QString vectorToQString(vector<string> &stringVector);

#endif /* COMMON_H_ */
