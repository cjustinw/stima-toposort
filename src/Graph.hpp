
#ifndef GRAPH_H
#define GRAPH_H

#include "Node.hpp"

class Graph{
    private:
        Node** vertex; /* Daftar semua mata kuliah */
        int numOfVertex; /* Jumlah semua mata kuliah */

        friend void TopoSort(Graph);

    public:
        /* Default Constructor */
        Graph(); 

        /* Copy Constructor */
        Graph(const Graph&);

        /* Destructor */
        ~Graph();

        /* Getter */
        int getNumOfVertex(); /* Return jumlah semua mata kuliah */

        /* Menambahkan mata kuliah ke daftar mata kuliah */
        void addVertex(Node&);

        /* Menghapus mata kuliah dari daftar mata kuliah */
        void delVertex(Node&);

        /* Menambahkan edge/prerequisites mata kuliah */
        /* Node src merupakan prerequisites dari node dest */
        void addEdge(Node& src, Node& dest);

        /* Menghapus edge/prerequisites mata kuliah */
        /* Node src merupakan prerequisites dari node dest */
        void delEdge(Node& src, Node& dest);

        /* Mencetak graph ke layar */
        void print();

        /* Return address dari node yang mengandung ID mata kuliah yang dicari */
        Node* searchVertex(string);

        /* */
        int getNumOfNodeWithoutPrev();
};

#endif