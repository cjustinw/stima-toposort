/* 
    Nama    : Christopher Justine William
    NIM     : 13519006
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Node.hpp"
#include "Graph.hpp"
#include "ListNode.hpp"

using namespace std;

/* 
    How to run :
    -   g++ -o TopoSort.exe TopoSort.cpp Graph.cpp ListNode.cpp Node.cpp
    -   ./TopoSort.exe
*/

void TopoSort(Graph G)
/* Melakukan pengurutan mata kuliah yang dapat diambil tiap semester dengan menggunakan topological sorting */
/* Mata kuliah yang diambil sudah memenuhi prerequisites */
{ 
    int count = 1;
    while(G.getNumOfVertex() != 0){ /* Cek graph ksosong */
        ListNode L;
        for(int i = 0; i < G.getNumOfVertex(); i++){ 
            /* Cari graph yang memiliki derajar masuk = 0 dan masukkan ke ListNode L */ 
            if(G.vertex[i]->getInDegree() == 0){
                L.add(*G.vertex[i]);
            }
        }
        cout << "Semester " << count << " :";
        for(int i = 0; i < L.getNumOfNode(); i++){
            /* Cetak ID untuk setiap node pada graph yang memiliki derajat masuk = 0 */
            cout << " " << L.list[i]->getID();
            /* Hapus setiap node yang memiliki derajat masuk = 0 dari graph */
            G.delVertex(*L.list[i]);
        }
        count++;
        cout << endl;
    }
}


int main()
{
    cout << "Penyusunan Rencana Kuliah dengan Topological Sort" << endl;
    cout << "(Penerapan Decrease and Conquer)" << endl << endl;;

    Graph G;

    string namaFile;
    cout << "Masukkan nama file: ";
    cin >> namaFile;
    cout << endl;

    /* Baca graph mata kuliah dari file */
    ifstream File("../test/" + namaFile);
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

    /* Melakukan topological sort pada graph yang sudah terbentuk */
    /* Argumen yang di pass ke fungsi TopoSort merupakan hasil copy constructor dari graph G*/
    TopoSort(G);

    cout << endl;
    system("pause");

    return 0;
}