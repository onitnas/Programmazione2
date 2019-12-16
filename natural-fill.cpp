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

template <class H> class BST {
private:
    Node<H> *root;
public:
    BST<H>() {
        root = NULL;
    }

    void setRoot(Node<H> *r) {
        root = r;
    }

    Node<H> *getRoot() {
        return root;
    }

    bool isEmpty() {
        return root == NULL;
    }

    void addNode(H v) {
        Node<H> *first = new Node<H>();
        first->setVal(v);
        if (isEmpty()) {
            setRoot(first);
        } else {
            Node<H> *aux = getRoot();
            Node<H> *auxn = NULL;
            while (aux != NULL) {
                auxn = aux;
                if (v <= aux->getVal()) {
                    aux = aux->getLeft();
                } else {
                    aux = aux->getRight();
                }
            }
            first->setFather(auxn);
            if (v <= auxn->getVal()) {
                auxn->setLeft(first);
            } else {
                auxn->setRight(first);
            }
        }
    }

    Node<H> *searchNode(H v) {
        if (isEmpty()) {
            return NULL;
        } else {
            Node<H> *aux = getRoot();
            while (aux != NULL && v != aux->getVal()) {
                if (v < aux->getVal()) {
                    aux = aux->getLeft();
                } else if (v > aux->getVal()) {
                    aux = aux->getRight();
                }
            }
            return aux;
        }
    }
    void naturalfill(Node<H> *aux, H *A, int &cont){
        if(aux!=NULL){
            naturalfill(aux->getLeft(),A,cont);
            aux->setVal(A[cont]);
            cont++;
            naturalfill(aux->getRight(),A,cont);
        }
    }
    void postorder(Node<H> * aux, fstream &out){
        if(aux!=NULL){
            postorder(aux->getLeft(),out);
            postorder(aux->getRight(),out);
            out<<aux->getVal()<<" ";
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
        in>>type;
        int n;
        in>>n;
        if(type=="int"){
            BST<int> * b1= new BST<int>();
            for(int j=0;j<n;j++){
                int dato;
                in>>dato;
                b1->addNode(dato);
            }
            int *A= new int[n];
            for(int j=0;j<n;j++){
                int dato;
                in>>dato;
                A[j]=dato;
            }
            int cont=0;
            b1->naturalfill(b1->getRoot(),A,cont);
            b1->postorder(b1->getRoot(),out);
        }else if(type=="double"){
            BST<double> * b1= new BST<double>();
            for(int j=0;j<n;j++){
                double dato;
                in>>dato;
                b1->addNode(dato);
            }
            double *A= new double[n];
            for(int j=0;j<n;j++){
                double dato;
                in>>dato;
                A[j]=dato;
            }
            int cont=0;
            b1->naturalfill(b1->getRoot(),A,cont);
     ing namespace std;
t       b1->postorder(b1->getRoot(),out);
        }
        out<<endl;
    }
}