#ifndef MINIFY_H
#define MINIFY_H
#include "QString"


QString minify(QString text);


QString removeAllNewlines(QString t);


/*
 * remove all characters between a closing tag and the next opening tag
*/
QString removeSapceBetweenTags(QString t);

#endif // MINIFY_H
