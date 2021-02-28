/* 
    Nama    : Christopher Justine William
    NIM     : 13519006
*/

#include <iostream>
#include <string>
#include "13519006-ListNode.hpp"

ListNode::ListNode()
/* Default Construktor */
{
    this->numOfNode = 0;
    this->list = NULL;
}

ListNode::~ListNode()
/* Destruktor */
{
    delete list;
}

int ListNode::getNumOfNode()
/* Return jumlah semua node */
{
    return this->numOfNode;
}

void ListNode::add(Node& N)
/* Menambahkan node ke daftar node */
{
    this->numOfNode++;
    Node** tmp = this->list;
    this->list = new Node*[this->numOfNode];
    if(tmp != NULL){
        for(int i = 0; i < this->numOfNode-1; i++){
            this->list[i] = tmp[i];
        }
    }
    delete tmp;
    this->list[this->numOfNode-1] = &N;
}