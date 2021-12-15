#include "common.h"
#include <iostream>
#include <vector>
#include "QString"
using namespace std;

bool isOpeningTag(string row){
    if ((row[0] == '<') && (row[1]!='/')){
        return true;
    }
    return false;
}

bool isClosingTag(string row){
    if ((row[0] == '<') && (row[1] == '/')) {
        return true;
    }
    return false;
}

bool isData(string row){
    if (isOpeningTag(row) || isClosingTag(row)){
        return false;
    }
    return true;
}

vector<string> xmlStringToVector(string &text){
    string textRows = "";

    /* replace all occurrences in place to separate tags from data */
    for (char c : text){
        if (c == '<'){
            textRows += "\n<";
        }else if (c == '>'){
            textRows += ">\n";
        }else{
            textRows += c;
        }
    }

    /* convert string to vector of strings */
    string line = "";
    vector<string> rows;
    for (char c : textRows){
        if (c != '\n'){
            line+= c;
        }else{
            rows.push_back(line);
            line = "";
        }
    }

    /* remove empty rows */
    vector<string> vectoredRows;
    for (string s : rows){
        if (s.size() >= 1){
            vectoredRows.push_back(s);
        }
    }

    return vectoredRows;
}

QString vectorToQString(vector<string> &stringVector){
    QString stringRows="";
    for (string str : stringVector){
        stringRows += QString::fromStdString(str); /* convert from string to QString */
        stringRows += '\n';
    }

    return stringRows;
}
