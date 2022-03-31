#pragma once

/**
 * @brief Clase Nodo Simplemente Enlazado
 * @tparam T
 */
template <typename T>
class Nodo_SE {
 public:
  /// Constructores
  Nodo_SE() : next_{nullptr}, data_{} {}  /// Constructor por defecto
  Nodo_SE(Nodo_SE<T>* const ptr, const T& data)
      : next_{ptr}, data_{data} {}  /// Constructor estándar
  // Nodo();  /// Constructor copia
  /// Destructores
  ~Nodo_SE() { next_ = nullptr; }
  /// Métodos
  /// Friend
  /// Sobrecargas Operadores
  /// Sobrecargas Conversiones
  /// Getters
  const Nodo_SE<T>* next() const { return next_; }
  const T& data() const { return data_; }
  /// Setters
  void next(Nodo_SE<T>* const ptr) { next_ = ptr; }
  void data(const T& data) { data_ = data; }
  Nodo_SE<T>*& next() { return next_; }
  T& data() { return data_; }

 protected:
 private:
  /// Atributos
  Nodo_SE<T>* next_;
  T data_;
};

/**
 * @brief Clase Nodo Doblemente Enlazado
 * @tparam T
 */
template <typename T>
class Nodo_DE {
 public:
  /// Constructores
  Nodo_DE() : next_{nullptr}, data_{} {}  /// Constructor por defecto
  Nodo_DE(Nodo_DE<T>* const ptr, const T& data)
      : next_{ptr}, data_{data} {}  /// Constructor estándar
  // Nodo_p();  /// Constructor copia
  /// Destructores
  ~Nodo_DE() {
    next_ = nullptr;
    prev_ = nullptr;
  }
  /// Métodos
  /// Friend
  /// Sobrecargas Operadores
  /// Sobrecargas Conversiones
  /// Getters
  const Nodo_DE<T>* next() const { return next_; }
  const Nodo_DE<T>* prev() const { return prev_; }
  const T& data() const { return data_; }
  /// Setters
  void next(Nodo_DE<T>* const ptr) { next_ = ptr; }
  void prev(Nodo_DE<T>* const ptr) { prev_ = ptr; }
  void data(const T& data) { data_ = data; }
  Nodo_DE<T>*& next() { return next_; }
  Nodo_DE<T>*& prev() { return prev_; }
  T& data() { return data_; }

 protected:
 private:
  /// Atributos
  Nodo_DE<T>* next_;
  Nodo_DE<T>* prev_;
  T data_;
};