#ifndef FORMAT_H_
#define FORMAT_H_
#include <vector>
#include "QString"
using namespace std;

void printIndentation(int n, QString &str);

QString format(vector<QString> &rows);

#endif /* FORMAT_H_ */
