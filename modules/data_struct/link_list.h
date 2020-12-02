//
// Created by lilua on 2020/12/1.
//

#ifndef GOODS_LINK_LIST_H
#define GOODS_LINK_LIST_H

#include "interface/length_interface.h"

template <class T>
struct LinkListNode{
  T value_;
  LinkListNode<T>*next_;
};

template <class T>
class LinkList: LengthInterface{
 public:
  LinkList();
 private:
  LinkListNode<T> *head_;
};


#endif  // GOODS_LINK_LIST_H
