#ifndef COMMON_H_
#define COMMON_H_
#include <vector>
#include "QString"
#include "mainwindow.h"
using namespace std;

bool isOpeningTag(QString row);

bool isClosingTag(QString row);

bool isData(QString row);

/*
 * Desc: remove all leading spaces
*/
QString leftTrim(string s);


/*
 * Desc: A function that takes an XML string and returns a vector of strings, separating
 * 			xml data and tags into rows
 * */
vector<QString> xmlStringToVector(QString &text);

#endif /* COMMON_H_ */
