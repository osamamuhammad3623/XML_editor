#include "consistency.h"
#include "common.h"
#include "QDebug"
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
            }else{
                tagStack.push(row);
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


bool checkTags( vector<QString> &incorrecTags ,vector<QString> rows){
    bool state = true;
    for (QString s: rows){

        /* <tag */
        if (s[0] == '<' && s[s.size()-1] != '>'){
            state = false;
            incorrecTags.push_back(s);
        }
        /* tag> */
        else if (s[0] != '<' && s[s.size()-1] == '>'){
            state = false;
            incorrecTags.push_back(s);
        }
    }

    return state;
}



