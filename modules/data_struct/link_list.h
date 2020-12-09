//
// Created by lilua on 2020/12/1.
//

#ifndef STORE_SYSTEM_LINK_LIST_H
#define STORE_SYSTEM_LINK_LIST_H

#include "interface/clean_interface.h"
#include "interface/display_interface.h"
#include "interface/find_interface.h"
#include "interface/insert_interface.h"
#include "interface/length_interface.h"
#include "interface/modify_interface.h"
#include "interface/remove_interface.h"
#include "interface/search_interface.h"

template <typename T>
class LinkList :
    // 接口继承
    private LengthInterface,
    private CleanInterface,
    private DisplayInterface,
    private RemoveInterface,
    private InsertInterface<T>,
    private ModifyInterface<T>,
    private FindInterface<T>,
    private SearchInterface<T> {
 public:
  LinkList();
  ~LinkList() override;

  // 重写的增删改查，清空和打印
  void clean() override;
  void display() override;
  T find(int aim)const override;
  bool insert(int aim, T data) override;
  bool modify(int aim, T data) override;
  bool remove(int aim) override;
  int search(T data) override;

 private:
  // 内部类用于封装
  class LinkListNode {
   public:
    // 定义两个构造函数方便编写代码
    LinkListNode();
    explicit LinkListNode(const T &data);

    // value_ 是数据结构的具体的值
    T value_;
    // next_ 是链表的下一位的地址
    LinkListNode *next_;
  };
  // 头指针，指向一个头节点
  // 实践证明，使用空的头节点将更方便编写代码
  LinkListNode *head_;
};

#include "link_list.tcc"

#endif  // STORE_SYSTEM_LINK_LIST_H
