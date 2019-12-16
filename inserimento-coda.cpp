#include <iostream>
#include <fstream>

using namespace std;
template <class H> class Node{
private:
    H val;
    Node<H> * next;
public:
    Node<H>(){
        val=0;
        next=NULL;
    }
    void setVal(H v){
        val=v;
    }
    void setNext(Node<H> * n){
        next=n;
    }
    H getVal(){
        return val;
    }
    Node<H> *getNext(){
        return next;
    }
};
template <class H> class Queue{
private:
    Node<H> * head;
public:
    Queue<H>(){
        head=NULL;
    }
    void setHead(Node<H> * h){
        head=h;
    }
    Node<H> * getHead(){
        return head;
    }
    bool isEmpty(){
        return head == NULL;
    }
    void insertNode(H v){
        Node<H> * first=new Node<H>();
        first->setVal(v);
        if(isEmpty()){
            setHead(first);
        }else{
            Node<H> * aux=getHead();
            while(aux->getNext()!=NULL){
                aux=aux->getNext();
            }
            aux->setNext(first);
        }
    }
    void stampa(Node<H> * aux, fstream &out){
        while(aux!=NULL){
            out<<aux->getVal()<<" ";
            aux=aux->getNext();
        }
        out<<endl;
    }
};
int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        string type;
        int op;
        in>>type;
        in>>op;
        if(type=="int"){
            Queue<int> *q1= new Queue<int>();
            for(int j=0;j<op;j++){
                int info;
                in>>info;
                q1->insertNode(info);
            }
            q1->stampa(q1->getHead(),out);
        }else if(type=="double"){
            Queue<double> *q1= new Queue<double>();
            for(int j=0;j<op;j++){
                double info;
                in>>info;
                q1->insertNode(info);
            }
            q1->stampa(q1->getHead(),out);
        }else if(type=="char"){
            Queue<char> *q1= new Queue<char>();
            for(int j=0;j<op;j++){
                char info;
                in>>info;
                q1->insertNode(info);
            }
            q1->stampa(q1->getHead(),out);
        }else if(type=="bool"){
            Queue<bool> *q1= new Queue<bool>();
            for(int j=0;j<op;j++){
                int info;
                in>>info;
                q1->insertNode(info);
            }
            q1->stampa(q1->getHead(),out);
        }
    }
}