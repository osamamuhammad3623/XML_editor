#include "minify.h"
#include "common.h"
#include "QString"
#include "QDebug"


QString minify(QString text){

    vector<QString> vec = xmlStringToVector(text);
    QString result = "";

    for (QString s : vec){
        result += s;
    }

    return result;
}
