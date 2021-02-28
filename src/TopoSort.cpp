#include <iostream>
#include <string>
#include <fstream>

#include "Graph.hpp"
#include "ListNode.hpp"

using namespace std;

void TopoSort(Graph G){
    int count = 1;
    while(G.getNumOfVertex() != 0){
        ListNode L;
        for(int i = 0; i < G.getNumOfVertex(); i++){
            if(G.vertex[i]->getInDegree() == 0){
                L.add(*G.vertex[i]);
            }
        }
        cout << "Semester " << count << " :";
        for(int i = 0; i < L.getNumOfNode(); i++){
            cout << " " << L.list[i]->getID();
            G.delVertex(*L.list[i]);
        }
        count++;
        cout << endl;
    }
}

int main(){
    Graph G;
    ifstream File("test4.txt");
    if(File.fail()) exit(1);

    string s;
    while(getline(File,s)){
        string id = ""; 
        bool isFirst = true;
        Node* first = NULL;
        for (char x : s){ 
            if (!(x == ',' || x == '.' || x == ' ')){ 
                id = id + x;
            } 
            else{
                if(x != ' '){
                    if(G.searchVertex(id) == NULL){
                        Node* tmp = new Node(id);
                        G.addVertex(*tmp);
                    }
                    if(isFirst){
                        first = G.searchVertex(id);
                        isFirst = false;
                    }
                    else{
                        G.addEdge(*G.searchVertex(id),*first);
                    }
                }
                id = "";   
            }
        } 
    }
    TopoSort(G);
    return 0;
}