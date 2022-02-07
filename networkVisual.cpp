#include "networkVisual.h"
#include "common.h"
#include "QFile"
#include "QTextStream"
using namespace std;

vector<vector<QString>> extractNetwork(vector<QString> &rows){

    vector<vector<QString>> adjacencyList;
    vector<QString> userList;

    for (int i=0; i< rows.size(); i++){
        if (rows[i] == "<id>"){
            userList.push_back(rows[i+1]); /* user ID is the first element */

            while (rows[++i] != "</user>"){
                if (rows[i] == "<follower>"){
                    i+=2;
                    userList.push_back(rows[i]);
                }
            }

            adjacencyList.push_back(userList);
            userList.clear();
        }
    }

    return adjacencyList;
}


void storeAdjacencyList(vector<vector<QString>> &adList){
    QString text="";
    for (int i=0; i< adList.size(); i++){
        for (int j=1; j < adList[i].size(); j++){
            text += adList[i][0] + " ";
            text += adList[i][j] + "\n";
        }
    }

    QFile file("nodes.txt");
    if (file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream stream(&file);
        stream << text;
        file.close();
    }
}


void visualize(void){
    system("python3 visualization.py");
}
