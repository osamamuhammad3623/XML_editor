#include "format.h"
#include "common.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void printIndentation(int n){
    for (int i=0; i<n;i++){
        cout << "   ";
    }
}


void printFormatted(vector<string> &rows){

    int level=-1;

    for(string s : rows){
        if(isOpeningTag(s) || isData(s)){
            level++;
        }else if (isClosingTag(s)){
            level--;
        }

        printIndentation(level);
        cout << s << endl;

    }
}
