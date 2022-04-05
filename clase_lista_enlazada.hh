#pragma once

#include <cassert>

#include "clase_nodo.hh"

/**
 * @brief Clase Lista Simplemente Enlazada
 * @tparam T
 */
template <typename T>
class Lista_SE {
 public:
  /// Constructores
  Lista_SE() : head_{nullptr} {}  /// Constructor por defecto
  Lista_SE(const T& data) {
    head_ = new Nodo_SE<T>;
    head_->data(data);
  }  /// Constructor estándar
  // ListaEnlazada();  /// Constructor copia
  /// Destructores
  ~Lista_SE() { head_ = nullptr; }
  /// Métodos
  void InsertHead(const T& dato) { head_ = new Nodo_SE<T>{head_, dato}; }
  void EraseHead() {
    Nodo_SE<T>* temp = head_->next();
    delete head_;
    head_ = temp;
  }
  void InsertAfter(Nodo_SE<T>* const prev, Nodo_SE<T>* const nodo) {
    Nodo_SE<T>* temp = prev->next();
    prev->next(nodo);
    nodo->next(temp);
  }
  void EraseAfter(Nodo_SE<T>* const prev) {
    Nodo_SE<T>* temp = prev->next()->next();
    delete prev->next();
    prev->next(temp);
  }
  bool Empty() const {
    if (head_ == nullptr) {
      return true;
    } else {
      return false;
    }
  }
  Nodo_SE<T>* Find(const T& dato) {
    Nodo_SE<T>* temp = head_;
    while (temp->data() != dato) {
      if (temp->next() != nullptr) {
        temp = temp->next();
      } else {
        return nullptr;
      }
    }
    return temp;
  }
  T erase_last() {
    if (this->Empty()) {
      throw "🧨";
    }
    Nodo_SE<T>* ptr{head_};
    Nodo_SE<T>* prev{head_};
    while (ptr->next() != nullptr) {
      prev = ptr;
      ptr = ptr->next();
    }
    auto copy = ptr->data();
    if (ptr != head_) {
      prev->next(nullptr);
    }
    delete ptr;
    return copy;
  }
  void Intercambiar() {
    assert(!this->Empty());
    assert(head().next() != nullptr);
    Nodo_SE<T> copy = head();
    this->EraseHead();
    this->InsertAfter(head(), copy);
  }
  /// Friend
  /// Sobrecargas Operadores
  /// Sobrecargas Conversiones
  /// Getters
  const Nodo_SE<T>& head() const { return *head_; }
  /// Setters
 protected:
 private:
  /// Atributos
  Nodo_SE<T>* head_;
};

/**
 * @brief Clase Lista Doblemente Enlazada
 * @tparam T
 */
template <typename T>
class Lista_DE {
 public:
  /// Constructores
  Lista_DE() : head_{nullptr} {}  /// Constructor por defecto
  Lista_DE(const T& data) {
    head_ = new Nodo_DE<T>;
    head_->data(data);
  }  /// Constructor estándar
  // ListaEnlazada();  /// Constructor copia
  /// Destructores
  ~Lista_DE() { head_ = nullptr; }
  /// Métodos
  void InsertHead(const T& dato) { head_ = new Nodo_DE<T>{head_, dato}; }
  void EraseHead() {
    Nodo_DE<T>* temp = head_->next();
    delete head_;
    head_ = temp;
  }
  void InsertAfter(Nodo_DE<T>* const prev, Nodo_DE<T>* const nodo) {
    Nodo_DE<T>* temp = prev->next();
    prev->next(nodo);
    nodo->next(temp);
  }
  void EraseAfter(Nodo_DE<T>* const prev) {
    Nodo_DE<T>* temp = prev->next()->next();
    delete prev->next();
    prev->next(temp);
  }
  bool Empty() const {
    if (head_ == nullptr) {
      return true;
    } else {
      return false;
    }
  }
  Nodo_DE<T>* Find(const T& dato) {
    Nodo_DE<T>* temp = head_;
    while (temp->data() != dato) {
      if (temp->next() != nullptr) {
        temp = temp->next();
      } else {
        return nullptr;
      }
    }
    return temp;
  }
  /// Friend
  /// Sobrecargas Operadores
  /// Sobrecargas Conversiones
  /// Getters
  const Nodo_DE<T>& head() const { return *head_; }
  /// Setters
 protected:
 private:
  /// Atributos
  Nodo_DE<T>* head_;
};