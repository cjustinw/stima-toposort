
#include <iostream>
#include <string>
#include "Node.hpp"

Node::Node()
/* Default Constructor */
{

}

Node::Node(string id)
/* Copy Constructor */
{
    this->id = id;
    this->inDegree = 0;
    this->outDegree = 0;
    this->prevNode = NULL;
    this->nextNode = NULL;
}

Node::~Node()
/* Destructor */
{
    delete this->prevNode;
    delete this->nextNode;
}

string Node::getID()
/* Return kode mata kuliah*/
{
    return this->id;
}

int Node::getInDegree()
/* Return jumlah derajat masuk*/
{
    return this->inDegree;
}

int Node::getOutDegree()
/* Return jumlah derjat keluar */
{
    return this->outDegree;
}

void Node::addNextNode(Node& N)
/* Menambahkan node successsor ke daftar node successsor */
{
    this->outDegree++;
    Node** tmp = this->nextNode;
    this->nextNode = new Node*[this->outDegree];
    if(tmp != NULL){
        for(int i = 0; i < this->outDegree-1; i++){
            this->nextNode[i] = tmp[i];
        }
    }
    delete tmp;
    this->nextNode[this->outDegree-1] = &N;
}

void Node::delNextNode(Node& N)
/* Menghapus node successsor dari daftar node successsor */
{
    for(int i = 0; i < this->outDegree; i++){
        if(this->nextNode[i]->getID() == N.getID()){
            for(int j = i; j < this->outDegree-1; j++){
                this->nextNode[j] = this->nextNode[j+1];
            }
            break;
        }
    }
    this->outDegree--;
    Node** tmp = this->nextNode;
    this->nextNode = new Node*[this->outDegree];
    if(tmp != NULL){
        for(int i = 0; i < this->outDegree; i++){
            this->nextNode[i] = tmp[i];
        }
    }
    delete tmp;
}

void Node::addPrevNode(Node& N)
/* Menambahkan node predecessor ke daftar node predecessor */
{
    this->inDegree++;
    Node** tmp = this->prevNode;
    this->prevNode = new Node*[this->inDegree];
    if(tmp !=  NULL){
        for(int i = 0; i < this->inDegree-1; i++){
            this->prevNode[i] = tmp[i];
        }
    }
    delete tmp;
    this->prevNode[this->inDegree-1] = &N;
}

void Node::delPrevNode(Node& N)
/* Menghapus node predecessor dari daftar node predecessor */
{
    for(int i = 0; i < this->inDegree; i++){
        if(this->prevNode[i]->getID() == N.getID()){
            for(int j = i; j < this->inDegree-1; j++){
                this->prevNode[j] = this->prevNode[j+1];
            }
            break;
        }
    }
    this->inDegree--;
    Node** tmp = this->prevNode;
    this->prevNode = new Node*[this->inDegree];
    if(tmp != NULL){
        for(int i = 0; i < this->inDegree; i++){
            this->prevNode[i] = tmp[i];
        }
    }
    delete tmp;
}

void Node::printPrevNode()
/* Mencetak daftar node predecessor sebagai prerequisites mata kuliah */
{
    for(int i = 0; i < this->inDegree; i++){
        cout << this->prevNode[i]->getID();
        if(i != this->inDegree-1){
            cout << ", ";
        }
    }
}