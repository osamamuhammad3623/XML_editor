#include "minify.h"
#include "QString"
#include "QDebug"


QString minify(QString text){

    QString newLinesRemoved = removeAllNewlines(text);
    return removeSapceBetweenTags(newLinesRemoved);
}

QString removeAllNewlines(QString t){
    QString temp = "";

    /* remove all newline characters */
    for (QChar c : t){
        if (c != '\n'){
            temp += c;
        }
    }
    return temp;
}

QString removeSapceBetweenTags(QString t){
    QString temp = "";

    for (int i=0; i< t.size(); i++){

        /* when you get to a closing tag */
        if (t[i] == '/'){
            temp+=t[i++];

            /* wait till its end */
            while (t[i] != '>'){
                temp += t[i++];
            }
            temp += t[i];

            /* if this closing tag is the last one */
            if ((t.size() - i) < 3){
                break;
            }

            /* ignore all characters till you reach < */
            while(t[i++] != '<'){}
            temp+= t[i];

        }else{
            temp += t[i];
        }
    }
    return temp;
}
