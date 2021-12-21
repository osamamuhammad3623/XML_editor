#ifndef CONSISTENCY_H
#define CONSISTENCY_H
#include <vector>
#include "QString"
using namespace std;

/*
 * Desc: return true if the closing tag {tag} corresponds to the opening tag {stackTop}
 * */
bool matchTopWithTag(QString stackTop, QString tag);


/*
 * Desc: A function checks if xml tags are balanced using a stack
 * 		function returns true if tags are balanced, false otherwise
 * */
bool checkBalancedTags(vector<QString> &rows);


/*
 * Desc : A function to check that all opening/closing tags are written correctly
 * input: incorrectTags: a vector to append the incorrectly written tags
 *        rows: a vector of rows of the XML
*/
bool checkTags( vector<QString> &incorrecTags ,vector<QString> rows);


#endif // CONSISTENCY_H
