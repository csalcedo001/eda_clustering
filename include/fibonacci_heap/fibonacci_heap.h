
#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <queue>
#include "NodoB.h"



/**
  * class Binomial_heap
  * 
  */

template<class T>
class Fibonacci_heap
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Fibonacci_heap () {
    m_size = 0;
    m_minNode = nullptr;
  }

  /**
   * Empty Destructor
   */
  ~Fibonacci_heap () {
    for(auto elem: this->m_heap) {
      delete(elem);
    }
  };

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @param  key
   */
  void Insert (NodoB<T> * key)
  {
    this->m_size++;
    this->m_heap.push_back(key);
    if(!m_minNode) m_minNode = key;
    else if(m_minNode->getM_key() > key->getM_key()) m_minNode = key;
  }


  /**
   * @return T
   */
  T Get_Min ()
  {
    return this->m_minNode->getM_key();
  }


  /**
   */
  void Delete_Min ()
  {
    this->m_size--;
    for(NodoB<T>* child: this->m_minNode->getM_Hijos()) {
      this->m_heap.push_back(child);
    }
    auto it = find(this->m_heap.begin(), this->m_heap.end(),m_minNode);
    this->m_heap.erase(it);
    m_minNode->getM_Hijos().clear();
    delete(this->m_minNode);
    this->m_minNode = nullptr;
    Compactar();
  }


  /**
   * @param  pNodo
   * @param  Value
   */
  void Decrease_key (NodoB<T> * pNodo, T Value)
  {
    if(pNodo->getM_key() < Value) return;
    pNodo->setM_key(Value);

    if(pNodo->getM_key() < pNodo->getM_pPadre()->getM_key()) {
      T temp = pNodo->getM_key();
      pNodo->setM_key(pNodo->getM_pPadre()->getM_key());
      Decrease_key(pNodo->getM_pPadre(),temp);
    }
  }


  /**
   * @param  p1
   * @param  p2
   */
  NodoB<T>* Unir(NodoB<T> * p1, NodoB<T> * p2)
  {
    if( p1->getM_key() < p2->getM_key()) {
      p1->getM_Hijos().push_back(p2);
      p2->setM_pPadre(p1);
      p1->setM_Grado(p1->getM_Grado()+1);

      return p1;
    }
    else {
      p2->getM_Hijos().push_back(p1);
      p1->setM_pPadre(p2);
      p2->setM_Grado(p2->getM_Grado()+1);

      return p2;
    }
  }


  /**
   */
  void Compactar ()
  {
    size_t maxGrado = floor(log2(this->m_size))+1;
    NodoB<T>* newRoots[maxGrado];
    NodoB<T> *temp, *elemtemp;
    std::list<NodoB<T>*> newHeap;
    NodoB<T>* newMin = nullptr;
    for(int i = 0; i < maxGrado; i++) newRoots[i] = nullptr;

    for(NodoB<T>* elem: this->m_heap) {
      elemtemp = elem;
      if(newRoots[elemtemp->getM_Grado()]) {
        
        while(true) {
          temp = newRoots[elemtemp->getM_Grado()];
          newRoots[elemtemp->getM_Grado()] = nullptr;

          if( elemtemp->getM_key() < temp->getM_key()) {
            elemtemp->getM_Hijos().push_back(temp);
            elemtemp->setM_Grado(elemtemp->getM_Grado()+1);
          }
          else {
            temp->getM_Hijos().push_back(elemtemp);  
            temp->setM_Grado(temp->getM_Grado()+1);  
            elemtemp = temp;
          }

          if(!newRoots[elemtemp->getM_Grado()]) {
            newRoots[elemtemp->getM_Grado()] = elemtemp;
            break;
          }      

        }
      }
      else {
        newRoots[elem->getM_Grado()] = elem;
      }
    }

    // for(NodoB<T>* elem: this->m_heap) {
    //   temp = elem;
    //   while(newRoots[temp->getM_Grado()] != nullptr) {
    //     temp = this->Unir(temp,newRoots[temp->getM_Grado()]);
    //     newRoots[temp->getM_Grado()-1] = nullptr;
    //   }
    //   newRoots[temp->getM_Grado()] = temp;
    // }
    // this->m_heap.clear();

    // for(auto e: newRoots) {
    //   if(e) {
    //     this->m_heap.push_back(e);
    //   }
    // }
    
    
    for(int i = 0; i < maxGrado; i++) {
      if(newRoots[i]) {
        if(!newMin) {
          newMin = newRoots[i];
        }
        else if(newMin->getM_key() > newRoots[i]->getM_key()){
          newMin = newRoots[i];
        }
        newHeap.push_back(newRoots[i]);

      }
    }

    // for(NodoB<T>* elem: this->m_heap) {
    //   if(!newMin) {
    //     newMin = elem;
    //     continue;
    //   }
    //   else if(newMin->getM_key() > elem->getM_key()){
    //     newMin = elem;
    //   }
    // }
    this->setM_heap(newHeap);
    this->m_minNode = newMin;
  }

  void print() {
    for(auto e: this->m_heap) {
      print(e,0);
    }
  }

  void print(NodoB<T>* n,int depth) {
    for(int i = 0; i < depth; i++) std::cout<<"\t";
    std::cout<<n->getM_key()<<"\n";
    for(auto e: n->getM_Hijos()) {
      print(e, depth+1);
    }

  }

  void write() {
    std::fstream file;
    std::queue<NodoB<T>*> q;
    NodoB<T>* cur;
    
    file.open("graphout", std::ios::in | std::ios::out | std::ios::trunc);
    file<<"digraph G {\n";

    for(NodoB<T>* e: this->m_heap) {
      if(e->getM_Hijos().size()) q.push(e);
      else file<<"\t"<<e->getM_key()<<";\n";
    }

    while(!q.empty()) {
      cur = q.front();
      q.pop();
      for(NodoB<T>* e: cur->getM_Hijos()) {
        file<<"\t"<<cur->getM_key()<<" -> "<<e->getM_key()<<";\n";
        q.push(e);
      }
    }
    file<<"}";
    file.close();
  }
  

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  
  NodoB<T>* m_minNode;
  int m_size;
  std::list<NodoB<T> * > m_heap;
  
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of m_size
   * @param new_var the new value of m_size
   */
  void setM_size (int new_var)   {
      m_size = new_var;
  }

  /**
   * Get the value of m_size
   * @return the value of m_size
   */
  int getM_size ()   {
    return m_size;
  }

  /**
   * Set the value of m_heap
   * @param new_var the new value of m_heap
   */
  void setM_heap (std::list<NodoB<T> * > new_var)   {
      m_heap = new_var;
  }

  /**
   * Get the value of m_heap
   * @return the value of m_heap
   */
  std::list<NodoB<T> * >& getM_heap ()   {
    return m_heap;
  }
private:

};

#endif // BINOMIAL_HEAP_H
