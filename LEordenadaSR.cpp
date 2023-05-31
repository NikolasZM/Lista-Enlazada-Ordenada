#include <iostream>
using namespace std;

template<class T>
class Nodo {
public:
    T valor;
    Nodo<T>* next;

    Nodo(T v, Nodo<T> *n);
};

template<class T>
Nodo<T>::Nodo(T v, Nodo<T> *n) {
    valor = v;
    next = n;
}

template<class T>
class Lista {
public:
    Nodo<T> * head;
    Nodo<T>* tmp;

    Lista();
    void add(T x);
    bool del(T x);
    bool find(T x, Nodo<T>* &pos);
    void prin();
};

template<class T>
Lista<T>::Lista(){
    head = nullptr;
    tmp = nullptr;
}

template<class T>
void Lista<T>::add(T x) {
    Nodo<T>* pos = nullptr;
    tmp = nullptr;
    if (!head) {
        head = new Nodo<T>(x, head);
    }
    else {
        if (find(x, pos)) {
            cout << "El numero ya existe\n";
        }
        else {
            if (pos) {
                tmp = new Nodo<T>(x, pos->next);
                pos->next = tmp;
            }
            else {
                tmp = new Nodo<T>(x, head);
                head = tmp;
            }
        }
    }
    
}

template<class T>
bool Lista<T>::find(T x, Nodo<T>* &pos) {
    tmp = head;
    if (!head) {
        return false;
    }

    if (head->valor == x) {
        pos = nullptr;
        return true;
    }

    for (Nodo<T>* p = head; p->next; p = p->next) {
        if (p->next->valor == x) {
            pos = p;
            return true;
        }
    }

    if (x<head->valor) {
        pos = nullptr;
        return false;
    }
    for (Nodo<T>* p = head; p->next; p = p->next) {
        
        if (x < p->next->valor) {
            pos = p;
            return false;
        }
        tmp = p->next;
    }
    pos = tmp;
    return false;
}

template<class T>
bool Lista<T>::del(T x) {
    Nodo<T>* pos;
    if (find(x, pos)) {
        if (pos) {
            tmp = pos->next;
            pos->next = tmp->next;
            delete tmp;
        }
        else {
            tmp = head;
            head = tmp->next;
            delete tmp;
        }
        return true;
    }
    else {
        cout << "No existe el elemento\n";
        return false;
    }
}

template<class T>
void Lista<T>::prin() {
    cout << "Head->";
    for (Nodo<T> *p = head; p ; p = p->next) {
        cout << p->valor << "->";
    }
    cout << "nullptr\n";
}


int main()
{
    Lista<int> Lista1;
    Lista1.prin();
    Lista1.add(3);

    Lista1.add(7);
    Lista1.prin();

    Lista1.add(7);
    Lista1.prin();

    Lista1.add(5);
    Lista1.prin();

    Lista1.add(1);

    Lista1.prin();

    Lista1.add(9);
    Lista1.prin();
    
    Lista1.del(1);
    Lista1.prin();

    Lista1.del(5);
    Lista1.prin();

    Lista1.del(9);
    Lista1.prin();

    Lista1.del(7);
    Lista1.prin();

    Lista1.del(7);
    Lista1.prin();


}