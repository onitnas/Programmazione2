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
    void setFahter(Node<H> * f){
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
        return root==NULL;
    }
    void insert(H v){
        Node<H> * first= new Node<H>();
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
            first->setFahter(auxn);
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
            Node<H> * aux=getRoot();
            while(aux!=NULL && aux->getVal() != v){
                if(v<aux->getVal()){
                    aux=aux->getLeft();
                }else{
                    aux=aux->getRight();
                }
            }
            return aux;
        }
    }
    void inorder(Node<H> * aux, fstream &out){
        if(aux!=NULL){
            inorder(aux->getLeft(),out);
            out<<aux->getVal()<<" ";
            inorder(aux->getRight(),out);
        }
    }
    void preorder(Node<H> * aux, fstream &out){
        if(aux!=NULL){
            out<<aux->getVal()<<" ";
            preorder(aux->getLeft(),out);
            preorder(aux->getRight(),out);
        }
    }
    void postorder(Node<H> * aux, fstream &out){
        if(aux!=NULL) {
            postorder(aux->getLeft(),out);
            postorder(aux->getRight(),out);
            out << aux->getVal()<<" ";
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
        string visit;
        in>>type;
        in>>n;
        in>>visit;
        if(type=="int"){
            BST<int> * b1= new BST<int>();
            for(int j=0;j<n;j++){
                int dato=0;
                in>>dato;
                b1->insert(dato);
            }
            if(visit=="inorder"){
                b1->inorder(b1->getRoot(),out);
            }else if(visit=="preorder"){
                b1->preorder(b1->getRoot(),out);
            }else if(visit=="postorder"){
                b1->postorder(b1->getRoot(),out);
            }
        }else if(type=="double"){
            BST<double> * b1= new BST<double>();
            for(int j=0;j<n;j++){
                double dato=0;
                in>>dato;
                b1->insert(dato);
            }
            if(visit=="inorder"){
                b1->inorder(b1->getRoot(),out);
            }else if(visit=="preorder"){
                b1->preorder(b1->getRoot(),out);
            }else if(visit=="postorder"){
                b1->postorder(b1->getRoot(),out);
            }
        }else if(type=="char"){
            BST<char> * b1= new BST<char>();
            for(int j=0;j<n;j++){
                char dato=' ';
                in>>dato;
                b1->insert(dato);
            }
            if(visit=="inorder"){
                b1->inorder(b1->getRoot(),out);
            }else if(visit=="preorder"){
                b1->preorder(b1->getRoot(),out);
            }else if(visit=="postorder"){
                b1->postorder(b1->getRoot(),out);
            }
        }else if(type=="bool"){
            BST<bool> * b1= new BST<bool>();
            for(int j=0;j<n;j++){
                bool dato=0;
                in>>dato;
                b1->insert(dato);
            }
            if(visit=="inorder"){
                b1->inorder(b1->getRoot(),out);
            }else if(visit=="preorder"){
                b1->preorder(b1->getRoot(),out);
            }else if(visit=="postorder"){
                b1->postorder(b1->getRoot(),out);
            }
        }
        out<<endl;
    }
}
