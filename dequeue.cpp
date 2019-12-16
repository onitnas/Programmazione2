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
    Node<H> * getNext(){
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
        return head==NULL;
    }
    void insertNode(H v){
        Node<H> * first= new Node<H>();
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
    void dequeue(){
        if(head==NULL){
            return;
        }else{
            setHead(getHead()->getNext());
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
        int n;
        in>>type;
        in>>n;
        if(type=="int"){
            Queue<int> *s1= new Queue<int>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="dequeue"){
                    s1->dequeue();
                }else{
                    s1->insertNode(atoi(op.substr(1).c_str()));
                }
            }
            s1->stampa(s1->getHead(),out);
        }else if(type=="double"){
            Queue<double> *s1= new Queue<double>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="dequeue"){
                    s1->dequeue();
                }else{
                    s1->insertNode(atof(op.substr(1).c_str()));
                }
            }
            s1->stampa(s1->getHead(),out);
        }else if(type=="char"){
            Queue<char> *s1= new Queue<char>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="dequeue"){
                    s1->dequeue();
                }else{
                    s1->insertNode(op[1]);
                }
            }
            s1->stampa(s1->getHead(),out);
        }else if(type=="bool"){
            Queue<bool> *s1= new Queue<bool>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="dequeue"){
                    s1->dequeue();
                }else{
                    s1->insertNode(atoi(op.substr(1).c_str()));
                }
            }
            s1->stampa(s1->getHead(),out);
        }
    }
}