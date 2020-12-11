//
// Created by lilua on 2020/12/10.
//

#ifndef STORE_SYSTEM_STACK_INTERFACE_H
#define STORE_SYSTEM_STACK_INTERFACE_H

#include "linear_list_interface.h"

template <typename T, template <typename> class ClassT>
class StackInterface : public LinearListInterface<T,ClassT>{
// public:
//  void clean() override;
//  virtual [[nodiscard]] bool isEmpty() const override = 0;
//  [[nodiscard]] bool isNotEmpty() const override;
//  bool find(int aim, T& data) const override;
//  ClassT<T>& insert(int aim, const T& data) override;
//  ClassT<T>& remove(int aim) override;
//
// private:
//  void display() const override;
//  [[nodiscard]] int getLength() const override;
//  void setLength(int length) override;
//  ClassT<T>& modify(int aim, const T& data) override;
//  int search(const T& data) const override;
};

#endif  // STORE_SYSTEM_STACK_INTERFACE_H
