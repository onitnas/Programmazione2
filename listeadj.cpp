#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

template <class H> class Nodo{
private:
    H val;
    Nodo<H> * next;
public:
    Nodo<H>(){
        val=0;
        next=NULL;
    }
    void setVal(H v){
        val=v;
    }
    void setNext(Nodo<H> * n){
        next=n;
    }
    H getVal(){
        return val;
    }
    Nodo<H> * getNext(){
        return next;
    }
};
template <class H> class Lista{
private:
    Nodo<H> * testa;
public:
    Lista<H>(){
        testa=NULL;
    }
    void setTesta(Nodo<H> * t){
        testa=t;
    }
    Nodo<H> * getTesta(){
        return testa;
    }
    bool isEmpty(){
        return testa==NULL;
    }
    void AddNodo(H v){
        Nodo<H> * nuovo= new Nodo<H>();
        nuovo->setVal(v);
        if(isEmpty()){
            setTesta(nuovo);
        }else{
            Nodo<H> * aux=getTesta();
            while(aux->getNext()!=NULL){
                aux=aux->getNext();
            }
            aux->setNext(nuovo);
        }
    }
    Nodo<H> * searchNodo(H v){
        if(isEmpty()){
            return NULL;
        }else{
            Nodo<H> * aux=getTesta();
            while(aux!=NULL && aux->getVal() != v){
                aux=aux->getNext();
            }
            return aux;
        }
    }
    void sortlista(){
        if(isEmpty()){
            return;
        }else{
            Nodo<H> * aux=getTesta();
            Nodo<H> * auxn=NULL;
            while(aux!=NULL){
                auxn=aux->getNext();
                while(auxn!=NULL){
                    if(aux->getVal()>auxn->getVal()){
                        H temp=aux->getVal();
                        aux->setVal(auxn->getVal());
                        auxn->setVal(temp);
                    }
                    auxn=auxn->getNext();
                }
                aux=aux->getNext();
            }
        }
    }
    string printLista(){
        stringstream ss;
        if(isEmpty()){
            cout<<"vuota";
        }else{
            Nodo<H> * aux=getTesta();
            while(aux!=NULL){
                ss<<" "<<aux->getVal();
                aux=aux->getNext();
            }
            return ss.str();
        }
    }
};
template <class H> class Grafo{
private:
    int n;
    int m;
    int dim;
    H * vertex;
    Lista<H> **ADJList;
public:
    Grafo<H>(){
        n=m=dim=0;
        vertex=NULL;
        ADJList=NULL;
    }
    Grafo<H>(int d){
        dim=d;
        n=m=0;
        vertex= new H[dim];
        ADJList = new Lista<H> *[dim];
        for(int i=0;i<dim;i++){
            vertex[i]=-1;
            ADJList[i]=new Lista<H>();
        }
    }
    bool isEmpty(){
        return n==0;
    }
    bool isFull(){
        return n>=dim;
    }
    int searchVertex(H v){
        if(isEmpty()){
            return -1;
        }else{
            for(int i=0;i<n;i++){
                if(vertex[i]==v){
                    return i;
                }
            }
            return -1;
        }
    }
    void addVertex(H v){
        if(isFull()){
            return;
        }else{
            if(searchVertex(v)<0){
                vertex[n]=v;
                n++;
            }else{
                return;
            }
        }
    }
    bool searchEdge(H v1, H v2){
        if(isEmpty()){
            return false;
        }else{
            if(searchVertex(v1)<0 || searchVertex(v2)<0){
                return false;
            }else{
                if(ADJList[searchVertex(v1)]->searchNodo(v2)!=NULL){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
    void addEdge(H v1, H v2){
        if(isEmpty()){
            return;
        }else{
            if(searchVertex(v1)<0 || searchVertex(v2)<0){
                return;
            }else{
                if(searchEdge(v1,v2)==false){
                    ADJList[searchVertex(v1)]->AddNodo(v2);
                    m++;
                }else{
                    return;
                }
            }
        }
    }
    void sortVertex(){
        if(isEmpty()){
            return;
        }else{
            for(int i=0;i<n-1;i++){
                for(int j=i;j<n;j++){
                    if(vertex[i]>vertex[j]){
                        swap(vertex[i],vertex[j]);
                    }
                }
            }
        }
    }
    string printGrafo(){
        if(isEmpty()){
            cout<<"vuoto";
        }else{
            stringstream ss;
            for(int i=0;i<n;i++){
                ss<<"("<<vertex[i];
                if(ADJList[i]->isEmpty()==false){
                    ADJList[i]->sortlista();
                    ss<<ADJList[i]->printLista();
                }
                ss<<") ";
            }
            ss<<endl;
            return ss.str();
        }
    }
};

int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        int vertex;
        int edge;
        string type;
        in>>vertex;
        in>>edge;
        in>>type;
        if(type=="int"){
            Grafo<int> * g1= new Grafo<int>(vertex);
            for(int j=0;j<vertex;j++){
                int dato;
                in>>dato;
                g1->addVertex(dato);
            }
            g1->sortVertex();
            for(int j=0;j<edge;j++) {
                string dato;
                in >> dato;
                int v1 = atoi(dato.substr(1).c_str());
                in >> dato;
                int v2 = atoi(dato.substr(0, 2).c_str());
                g1->addEdge(v1, v2);
            }
            out<<g1->printGrafo();
        }else if(type=="double"){
            Grafo<double> * g1= new Grafo<double>(vertex);
            for(int j=0;j<vertex;j++){
                double dato;
                in>>dato;
                g1->addVertex(dato);
            }
            g1->sortVertex();
            for(int j=0;j<edge;j++) {
                string dato;
                in >> dato;
                double v1 = atof(dato.substr(1).c_str());
                in >> dato;
                double v2 = atof(dato.substr(0,3).c_str());
                g1->addEdge(v1, v2);
            }
            out<<g1->printGrafo();
        }else if(type=="char"){
            Grafo<char> * g1= new Grafo<char>(vertex);
            for(int j=0;j<vertex;j++){
                string dato;
                in>>dato;
                g1->addVertex(dato[0]);
            }
            g1->sortVertex();
            for(int j=0;j<edge;j++) {
                string dato;
                in >> dato;
                char v1 =dato[1];
                in >> dato;
                char v2 =dato[0];
                g1->addEdge(v1, v2);
            }
            out<<g1->printGrafo();
        }
    }
}