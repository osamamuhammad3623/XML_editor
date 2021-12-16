#include "format.h"
#include "common.h"
using namespace std;


QString format(vector<QString> &rows){

    QString formatted = "";
    int level=-1;

    for(QString s : rows){
        if(isOpeningTag(s) || isData(s)){
            level++;
        }else if (isClosingTag(s)){
            level--;
        }

        /* printing indentation levels */
        for (int i=0; i<level;i++){
            formatted += "     ";
        }

        formatted += s;
        formatted += '\n';
    }

    return formatted;
}
