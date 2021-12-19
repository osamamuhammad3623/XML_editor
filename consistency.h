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

#endif // CONSISTENCY_H
