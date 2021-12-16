#include "format.h"
#include "common.h"
using namespace std;

void printIndentation(int n, QString &str){
    for (int i=0; i<n;i++){
         str += "      ";
    }
}

QString format(vector<QString> &rows){

    QString formatted = "";
    int level=-1;
    bool prevData=false;
    QString prev = "";

    for(QString s : rows){
        if(isOpeningTag(s)){
            level++;
        }else if (isData(s) && (!prevData)){
            level++;
        }else if (isClosingTag(s)){
            level--;
        }

        /* to avoid level shifts */
        if (isOpeningTag(s) && isClosingTag(prev)){
            level--;
        }

        /* printing indentation levels */
        printIndentation(level, formatted);

        formatted += s;
        formatted += '\n';

        prev = s;
    }

    return formatted;
}
