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
 * Desc: A function that checks if data is placed not between an opening & closing tags
 *      - Data must be between an opening tag and a closing tag
*/
bool checkDataPosition(vector<QString> &rows);

#endif // CONSISTENCY_H
