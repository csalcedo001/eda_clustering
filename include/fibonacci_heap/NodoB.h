
#ifndef NODOB_H
#define NODOB_H

#include <string>
#include <list>



/**
  * class NodoB
  * 
  */

template<class T>
class NodoB
{
public:

  // Constructors/Destructors
  //  

  NodoB (T& key):m_key(key) {
    this->m_Grado = 0;
    marcado = false;
  }


  /**
   * Empty Constructor
   */
  NodoB () {

    this->m_Grado = 0;
    marcado = false;
  };

  /**
   * Empty Destructor
   */
  ~NodoB () {
    for(auto elem: this->m_Hijos) {
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

  int m_Grado;
  T m_key;
  std::list< NodoB<T> * > m_Hijos;
  NodoB<T> * m_pPadre;
  bool marcado;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of m_Grado
   * @param new_var the new value of m_Grado
   */
  void setM_Grado (int new_var)   {
      m_Grado = new_var;
  }

  /**
   * Get the value of m_Grado
   * @return the value of m_Grado
   */
  int getM_Grado ()   {
    return m_Grado;
  }

  /**
   * Set the value of m_key
   * @param new_var the new value of m_key
   */
  void setM_key (T new_var)   {
      m_key = new_var;
  }

  /**
   * Get the value of m_key
   * @return the value of m_key
   */
  T getM_key ()   {
    return m_key;
  }

  /**
   * Set the value of m_Hijos
   * @param new_var the new value of m_Hijos
   */
  void setM_Hijos (std::list< NodoB<T> * > new_var)   {
      m_Hijos = new_var;
  }

  /**
   * Get the value of m_Hijos
   * @return the value of m_Hijos
   */
  std::list< NodoB<T> * >& getM_Hijos ()   {
    return m_Hijos;
  }

  /**
   * Set the value of m_pPadre
   * @param new_var the new value of m_pPadre
   */
  void setM_pPadre (NodoB<T> * new_var)   {
      m_pPadre = new_var;
  }

  /**
   * Get the value of m_pPadre
   * @return the value of m_pPadre
   */
  NodoB<T> * getM_pPadre ()   {
    return m_pPadre;
  }
private:

};

#endif // NODOB_H
