#include <iostream>
#include <fstream>

using namespace std;
template <class H> class Node{
private:
    H val;
    Node<H> * next;
public:
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
            first->setNext(getHead());
            setHead(first);
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
            Stack<int> *q1= new Stack<int>();
            for(int j=0;j<op;j++){
                int info;
                in>>info;
                q1->push(info);
            }
            q1->stampa(q1->getHead(),out);
        }else if(type=="double"){
            Stack<double> *q1= new Stack<double>();
            for(int j=0;j<op;j++){
                double info;
                in>>info;
                q1->push(info);
            }
            q1->stampa(q1->getHead(),out);
        }else if(type=="char"){
            Stack<char> *q1= new Stack<char>();
            for(int j=0;j<op;j++){
                char info;
                in>>info;
                q1->push(info);
            }
            q1->stampa(q1->getHead(),out);
        }else if(type=="bool"){
            Stack<bool> *q1= new Stack<bool>();
            for(int j=0;j<op;j++){
                int info;
                in>>info;
                q1->push(info);
            }
            q1->stampa(q1->getHead(),out);
        }
    }
}