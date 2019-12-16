#include <iostream>
#include <fstream>

using namespace std;
template <class H> class Node{
private:
    H val;
    Node<H> * father;
    Node<H> * left;
    Node<H> * right;
public:
    Node<H>(){
        val=0;
        father=left=right=NULL;
    }
    void setVal(H v){
        val=v;
    }
    void setFather(Node<H> * f){
        father=f;
    }
    void setLeft(Node<H> * l){
        left=l;
    }
    void setRight(Node<H> * r){
        right=r;
    }
    H getVal(){
        return val;
    }
    Node<H> * getFather(){
        return father;
    }
    Node<H> * getLeft(){
        return left;
    }
    Node<H> * getRight(){
        return right;
    }
};
template <class H> class BST{
private:
    Node<H> * root;
public:
    BST<H>(){
        root=NULL;
    }
    void setRoot(Node<H> * r){
        root=r;
    }
    Node<H> * getRoot(){
        return root;
    }
    bool isEmpty(){
        return root == NULL;
    }
    void addNode(H v){
        Node<H> * first=new Node<H>();
        first->setVal(v);
        if(isEmpty()){
            setRoot(first);
        }else{
            Node<H> * aux=getRoot();
            Node<H> * auxn=NULL;
            while(aux!=NULL){
                auxn=aux;
                if(v<=aux->getVal()){
                    aux=aux->getLeft();
                }else{
                    aux=aux->getRight();
                }
            }
            first->setFather(auxn);
            if(v<=auxn->getVal()){
                auxn->setLeft(first);
            }else{
                auxn->setRight(first);
            }
        }
    }
    Node<H> * searchNode(H v){
        if(isEmpty()){
            return NULL;
        }else{
            Node<H> * aux= getRoot();
            while(aux!=NULL && v!=aux->getVal()){
                if(v<aux->getVal()){
                    aux=aux->getLeft();
                }else if(v>aux->getVal()){
                    aux=aux->getRight();
                }
            }
            return aux;
        }
    }
    Node<H> * getMin(Node<H> * aux){
        Node<H> * min=aux;
        while(min->getLeft()!=NULL){
            min=min->getLeft();
        }
        return min;
    }
    void trapianta(Node<H> * aux, Node<H> * auxn){
        if(aux->getFather()==NULL){
            setRoot(auxn);
        }else if(aux==aux->getFather()->getLeft()){
            aux->getFather()->setLeft(auxn);
        }else if(aux==aux->getFather()->getRight()){
            aux->getFather()->setRight(auxn);
        }
        if(auxn!=NULL){
            auxn->setFather(aux->getFather());
        }
    }
    void deleteNode(H v){
        if(isEmpty()){
            return;
        }else{
            Node<H> * aux= searchNode(v);
            if(aux!=NULL){
                if(aux->getLeft()==NULL){
                    trapianta(aux,aux->getRight());
                }else if(aux->getRight()==NULL){
                    trapianta(aux,aux->getLeft());
                }else{
                    Node<H> *y=getMin(aux->getRight());
                    if(y->getFather()!=aux){
                        trapianta(y,y->getRight());
                        y->setRight(aux->getRight());
                        y->getRight()->setFather(y);
                    }
                    trapianta(aux,y);
                    y->setLeft(aux->getLeft());
                    y->getLeft()->setFather(y);
                }
            }
        }
    }
    void inorder(Node<H> * aux, H &cont){
        if(aux!=NULL){
            inorder(aux->getLeft(),cont);
            cont+=aux->getVal();
            inorder(aux->getRight(),cont);
        }
    }
    H peso(Node<H> * aux, H &cont){
        if(aux!=NULL){
            inorder(aux,cont);
            return cont;
        }
    }
};
int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        string type;
        int n;
        in>>type;
        in>>n;
        if(type=="int"){
            BST<int> *b1= new BST<int>();
            for(int j=0;j<n;j++){
                string dato;
                in>>dato;
                if(dato[0]=='i'){
                    b1->addNode(atoi(dato.substr(4).c_str()));
                }else if(dato[0]=='c'){
                    b1->deleteNode(atoi(dato.substr(5).c_str()));
                }
            }
            int dato;
            in>>dato;
            int cont=0;
            out<<b1->peso(b1->searchNode(dato),cont)<<endl;
        }else if(type=="double"){
            BST<double> *b1= new BST<double>();
            for(int j=0;j<n;j++){
                string dato;
                in>>dato;
                if(dato[0]=='i'){
                    b1->addNode(atof(dato.substr(4).c_str()));
                }else if(dato[0]=='c'){
                    b1->deleteNode(atof(dato.substr(5).c_str()));
                }
            }
            double dato;
            in>>dato;
            double cont=0;
            out<<b1->peso(b1->searchNode(dato),cont)<<endl;
        }
    }
}