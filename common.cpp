#include "common.h"
#include "QString"
using namespace std;

bool isOpeningTag(QString row){
    if ((row[0] == '<') && (row[1]!='/') && (row[row.size()-1] == '>')){
        return true;
    }
    return false;
}

bool isClosingTag(QString row){
    if ((row[0] == '<') && (row[1] == '/') && (row[row.size()-1] == '>')) {
        return true;
    }
    return false;
}

bool isData(QString row){
    /* a row contains data if it's neither an opening tag nor a closing one */
    return (!(isOpeningTag(row)) && (!isClosingTag(row)));
}

vector<QString> xmlStringToVector(QString &text){
    QString textRows = "";

    /* replace all occurrences in place to separate tags from data */
    for (QChar c : text){
        if (c == '<'){
            textRows += "\n<";
        }else if (c == '>'){
            textRows += ">\n";
        }else{
            textRows += c;
        }
    }

    /* convert QString to vector of QStrings */
    QString line = "";
    vector<QString> rows;
    for (QChar c : textRows){
        if (c != '\n'){
            line+= c;
        }else{
            rows.push_back(line);
            line = "";
        }
    }

    /* remove empty rows */
    vector<QString> vectoredRows;
    for (QString s : rows){
        if (s.size() >= 1){
            vectoredRows.push_back(s);
        }
    }

    return vectoredRows;
}
