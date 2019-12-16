#include <iostream>
#include <fstream>
#include <cstdlib>
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
    void enqueue(H v){
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
    void dequeue(){
        if(isEmpty()){
            return;
        }else{
            head=head->getNext();
        }
    }
    void stampa(fstream &out){
        if(isEmpty()){
            return;
        }else {
            Node<H> *aux = getHead();
            while (aux != NULL) {
                out << aux->getVal() << " ";
                aux = aux->getNext();
            }
            out << endl;
        }
    }
};

template <class H> class Stack{
private:
    Node<H> * head;
public:
    Stack<H>(){
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
    void push(H v){
        Node<H> * first=new Node<H>();
        first->setVal(v);
        if(isEmpty()){
            setHead(first);
        }else{
            first->setNext(head);
            setHead(first);
        }
    }
    void pop(){
        if(isEmpty()){
            return;
        }else{
            head=head->getNext();
        }
    }
    void travasa(Queue<H> * q1){
        while(!isEmpty()){
            q1->enqueue(getHead()->getVal());
            pop();
        }
    }
    void stampa(Node<H> * aux, fstream &out){
        if(isEmpty()){
            return;
        }else
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
            Stack<int> *s1= new Stack<int>();
            Queue<int> *q1= new Queue<int>();
            for(int j=0;j<op;j++){
                string dato;
                in>>dato;
                if(dato[0]=='e'){
                    q1->enqueue(atoi(dato.substr(2).c_str()));
                }else if(dato=="pop"){
                    s1->pop();
                }else if(dato=="travasa"){
                   s1->travasa(q1);
               }else if(dato[0]=='p'){
                    s1->push(atoi(dato.substr(2).c_str()));
                }else if(dato=="dequeue"){
                    q1->dequeue();
                }
            }
            q1->stampa(out);
        }else if(type=="double"){
            Stack<double> *s1= new Stack<double>();
            Queue<double> *q1= new Queue<double>();
            for(int j=0;j<op;j++){
                string dato;
                in>>dato;
                if(dato[0]=='e'){
                    q1->enqueue(atof(dato.substr(2).c_str()));
                }else if(dato=="pop"){
                    s1->pop();
                }else if(dato[0]=='p'){
                    s1->push(atof(dato.substr(2).c_str()));
                }else if(dato=="dequeue"){
                    q1->dequeue();
                }else if(dato=="travasa"){
                    s1->travasa(q1);
                }
            }
            q1->stampa(out);
        }else if(type=="char"){
            Stack<char> *s1= new Stack<char>();
            Queue<char> *q1= new Queue<char>();
            for(int j=0;j<op;j++){
                string dato;
                in>>dato;
                if(dato[0]=='e'){
                    q1->enqueue(dato[2]);
                }else if(dato=="pop"){
                    s1->pop();
                }else if(dato[0]=='p'){
                    s1->push(dato[2]);
                }else if(dato=="dequeue"){
                    q1->dequeue();
                }else if(dato=="travasa"){
                    s1->travasa(q1);
                }
            }
            q1->stampa(out);
        }else if(type=="bool"){
            Stack<bool> *s1= new Stack<bool>();
            Queue<bool> *q1= new Queue<bool>();
            for(int j=0;j<op;j++){
                string dato;
                in>>dato;
                if(dato[0]=='e'){
                    q1->enqueue(atoi(dato.substr(2).c_str()));
                }else if(dato=="pop"){
                    s1->pop();
                }else if(dato[0]=='p'){
                    s1->push(atoi(dato.substr(2).c_str()));
                }else if(dato=="dequeue"){
                    q1->dequeue();
                }else if(dato=="travasa"){
                    s1->travasa(q1);
                }
            }
            q1->stampa(out);
        }
    }
}