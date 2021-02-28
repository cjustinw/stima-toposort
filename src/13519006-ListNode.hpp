/* 
    Nama    : Christopher Justine William
    NIM     : 13519006
*/

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "13519006-Node.hpp"
#include "13519006-Graph.hpp"

class ListNode{
    private:
        Node** list; /* Daftar semua node */
        int numOfNode; /* Jumalh semua node */

        friend void TopoSort(Graph);

    public:
        /* Default Construktor */
        ListNode();

        /* Destruktor */
        ~ListNode();

        /* Getter */
        int getNumOfNode(); /* Return jumlah semua node */

        /* Menambahkan node ke daftar node */
        void add(Node&);
    
};

#endif