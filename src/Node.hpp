#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node{
    private:
        string id; /* Kode mata kuliah */
        Node** prevNode; /* Daftar node predecessor */
        Node** nextNode; /* Daftar node successor */
        int inDegree; /* Derajat masuk */
        int outDegree; /* Derajat keluar */

        friend class Graph;
        
    public:
        /* Default Constructor */
        Node();             

        /* User Define Constructor */
        Node(string);

        /* Destructor */
        ~Node();

        /* Getter */
        string getID();  /* Return kode mata kuliah */
        int getInDegree(); /* Return jumlah derajat masuk */
        int getOutDegree(); /* Return jumlah derjat keluar */

        /* Menambahkan node successsor ke daftar node successsor */
        void addNextNode(Node&);

        /* Menghapus node successsor dari daftar node successsor */
        void delNextNode(Node&);

        /* Menambahkan node predecessor ke daftar node predecessor */
        void addPrevNode(Node&);

        /* Menghapus node predecessor dari daftar node predecessor */
        void delPrevNode(Node&);

        /* Mencetak daftar node predecessor sebagai prerequisites mata kuliah */
        void printPrevNode();
};

#endif