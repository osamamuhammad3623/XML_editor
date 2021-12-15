#include "format.h"
#include "common.h"
#include <iostream>
#include <stack>
#include <vector>
#include "QString"
using namespace std;


QString format(vector<string> &rows){

    QString formatted = "";
    int level=-1;

    for(string s : rows){
        if(isOpeningTag(s) || isData(s)){
            level++;
        }else if (isClosingTag(s)){
            level--;
        }

        /* printing indentation levels */
        for (int i=0; i<level;i++){
            formatted += "     ";
        }
        formatted += QString::fromStdString(s);
        formatted += '\n';
    }

    return formatted;
}
