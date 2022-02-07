#ifndef NETWORKVISUAL_H
#define NETWORKVISUAL_H
#include "common.h"
#include <vector>

vector<vector<QString>> extractNetwork(vector<QString> &rows);

void storeAdjacencyList(vector<vector<QString>> &adList);

void visualize(void);

#endif // NETWORKVISUAL_H
