#include "consistency.h"
#include "common.h"
#include <stack>
using namespace std;


bool matchTopWithTag(QString stackTop, QString tag){
    QString tempTag="";
    for(QChar c : tag){
        if(c != '/'){
            tempTag+= c;
        }
    }

    return (stackTop == tempTag);
}


bool checkBalancedTags(vector<QString> &rows){

    stack<QString> tagStack;

    /* adding tags to stack */
    for (QString row : rows){

        /* if the tag is opening, just push to stack */
        if (isOpeningTag(row)) {
            tagStack.push(row);

        } else if (isClosingTag(row)) {
            /* if it's a closing tag,,,
             * if it corresponds to the peek tag, then pop the peek
             * */
            if (matchTopWithTag(tagStack.top(), row)) {
                tagStack.pop();
            }
        }
        /* else: row contains data, ignore it */
    }

    if (tagStack.empty()) {
        return true;
    } else {
        return false;
    }
}


bool checkDataPosition(vector<QString> &rows){

    for (int i=0; i< rows.size() -1; i++){
        if (isClosingTag(rows[i]) && isData(rows[i+1])){
            return false;
        }
    }
    return true;
}







