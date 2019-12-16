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
template <class H> class Stack{
private:
    Node<H> * head;
public:
    Stack<H>(){
        head=NULL;
    }
    bool isEmpty(){
        return head==NULL;
    }
    void setHead(Node<H> * h){
        head=h;
    }
    Node<H> * getHead(){
        return head;
    }
    void push(H v){
        Node<H> * first= new Node<H>();
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
            Stack<int> *s1= new Stack<int>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="pop"){
                    s1->pop();
                }else{
                    s1->push(atoi(op.substr(1).c_str()));
                }
            }
            s1->stampa(s1->getHead(),out);
        }else if(type=="double"){
            Stack<double> *s1= new Stack<double>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="pop"){
                    s1->pop();
                }else{
                    s1->push(atof(op.substr(1).c_str()));
                }
            }
            s1->stampa(s1->getHead(),out);
        }else if(type=="char"){
            Stack<char> *s1= new Stack<char>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="pop"){
                    s1->pop();
                }else{
                    s1->push(op[1]);
                }
            }
            s1->stampa(s1->getHead(),out);
        }else if(type=="bool"){
            Stack<bool> *s1= new Stack<bool>();
            for(int j=0;j<n;j++){
                string op;
                in>>op;
                if(op=="pop"){
                    s1->pop();
                }else{
                    s1->push(atoi(op.substr(1).c_str()));
                }
            }
            s1->stampa(s1->getHead(),out);
        }
    }
}

