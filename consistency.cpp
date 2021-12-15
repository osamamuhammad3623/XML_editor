#include "consistency.h"
#include "common.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


bool matchTopWithTag(string stackTop, string tag){
    string tempTag="";
    for(char c : tag){
        if(c != '/'){
            tempTag+= c;
        }
    }

    return (stackTop == tempTag);
}


bool checkBalancedTags(vector<string> &rows){

    stack<string> tagStack;

    /* adding tags to stack */
    for (string row : rows){

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
