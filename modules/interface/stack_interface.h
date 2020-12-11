//
// Created by lilua on 2020/12/10.
//

#ifndef STORE_SYSTEM_STACK_INTERFACE_H
#define STORE_SYSTEM_STACK_INTERFACE_H

#include "linear_list_interface.h"

template <typename T>
class StackInterface : public LinearListInterface<T>{
 public:
  void clean() override;
  [[nodiscard]] bool isEmpty() const override;
  [[nodiscard]] bool isNotEmpty() const override;
  bool find(int aim, T& data) const override;
  InsertInterface<T>& insert(int aim, const T& data) override;
  RemoveInterface<T>& remove(int aim) override;

 private:
  void display() const override;
  [[nodiscard]] int getLength() const override;
  void setLength(int length) override;
  ModifyInterface<T>& modify(int aim, const T& data) override;
  int search(const T& data) const override;
};

#endif  // STORE_SYSTEM_STACK_INTERFACE_H
