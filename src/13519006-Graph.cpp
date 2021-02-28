/* 
    Nama    : Christopher Justine William
    NIM     : 13519006
*/

#include <iostream>
#include <string>
#include "13519006-Graph.hpp"

Graph::Graph()
/* Default Constructor */
{
    this->numOfVertex = 0;
    this->vertex = NULL;
}

Graph::Graph(const Graph& G)
/* Copy Constructor */
{
    this->numOfVertex = G.numOfVertex;
    this->vertex = new Node*[this->numOfVertex];
    for(int i = 0; i < this->numOfVertex; i++){
        this->vertex[i] = new Node(G.vertex[i]->getID());
    }
    for(int i = 0; i < this->numOfVertex; i++){
        for(int j = 0; j < G.vertex[i]->outDegree; j++){           
            this->addEdge(*this->vertex[i], *this->searchVertex(G.vertex[i]->nextNode[j]->getID()));
        }
    }
}

Graph::~Graph()
/* Destructor */
{
    for(int i = 0; i < this->numOfVertex; i++)
    
    {
        delete this->vertex[i];
    }
    delete this->vertex;
}

int Graph::getNumOfVertex()
/* Return jumlah semua mata kuliah */
{
    return this->numOfVertex;
}

void Graph::addVertex(Node& N)
/* Menambahkan mata kuliah ke daftar mata kuliah */
{
    this->numOfVertex++;
    Node** tmp = this->vertex;
    this->vertex = new Node*[this->numOfVertex];
    if(tmp != NULL){
        for(int i = 0; i < this->numOfVertex-1; i++){
            this->vertex[i] = tmp[i];
        }
    }
    delete tmp;
    this->vertex[this->numOfVertex-1] = &N;
}

void Graph::delVertex(Node& node)
/* Menghapus mata kuliah dari daftar mata kuliah */
{
    Node* N = this->searchVertex(node.getID());
    while(N->outDegree > 0){
        this->delEdge(*N,*N->nextNode[0]);
    }
    while(N->inDegree > 0){
        this->delEdge(*N->prevNode[0], *N);
    }
    for(int i = 0; i < this->numOfVertex; i++){
        if(this->vertex[i] == N){
            for(int j = i; j < this->numOfVertex-1;j++){
                this->vertex[j] = this->vertex[j+1];
            }
            break;
        }    
    }
    delete N;  
    this->numOfVertex--;
    Node** tmp = this->vertex;
    this->vertex = new Node*[this->numOfVertex];
    for(int i = 0; i < this->numOfVertex; i++){
        this->vertex[i] = tmp[i];
    }
    delete tmp; 
}

void Graph::addEdge(Node& src, Node& dest)
/* Menambahkan edge/prerequisites mata kuliah */
/* Node src merupakan prerequisites dari node dest */
{
    src.addNextNode(dest);
    dest.addPrevNode(src);
}

void Graph::delEdge(Node& src, Node& dest)
/* Menghapus edge/prerequisites mata kuliah */
/* Node src merupakan prerequisites dari node dest */
{
    src.delNextNode(dest);
    dest.delPrevNode(src);
}

void Graph::print()
/* Mencetak graph ke layar */
{
    for(int i = 0; i < this->numOfVertex; i++){
        cout << this->vertex[i]->getID() << "(" << this->vertex[i]->getInDegree() << "," <<this->vertex[i]->getOutDegree() << ")" << " : ";
        this->vertex[i]->printPrevNode();
        cout << endl;
    }
}

Node* Graph::searchVertex(string S)
/* Return address dari node yang mengandung ID mata kuliah yang dicari */
{
    for(int i = 0; i < this->numOfVertex; i++){
        if(this->vertex[i]->getID() == S){
            return this->vertex[i];
        }
    }
    return NULL;
}