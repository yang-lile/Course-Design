//
// Created by lilua on 2020/12/1.
//

#ifndef STORE_SYSTEM_LINK_LIST_H
#define STORE_SYSTEM_LINK_LIST_H

#include <iostream>

#include "interface/linear_list_interface.h"

template <typename T>
class LinkList :
    // 接口继承
    private LinearListInterface<T, LinkList> {
 public:
  LinkList();
  ~LinkList() override;

  // 重写的增删改查，清空和打印
  void clean() override;
  void display() const override;
  bool find(int aim, T &data) const override;
  LinkList<T> &insert(int aim, const T &data) override;
  LinkList<T> &modify(int aim, const T &data) override;
  LinkList<T> &remove(int aim) override;
  int search(const T &data) const override;
  [[nodiscard]] unsigned getLength() const override;
  void setLength(unsigned length) override;
  [[nodiscard]] bool isEmpty() const override;
  [[nodiscard]] bool isNotEmpty() const override;

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

/* 下面为实现 */

/// \链表的构造函数
/// \tparam T 链表的类型
template <class T>
LinkList<T>::LinkList() : head_(nullptr) {
  head_ = new LinkListNode();
}
/// \链表的析构函数
/// \tparam T 链表的类型
template <typename T>
LinkList<T>::~LinkList() {
  // 释放所有的有值节点
  if (this->isNotEmpty()) this->clean();
  // 释放头节点
  delete this->head_;
}
/// 节点的构造函数
/// \tparam T 链表的类型
template <typename T>
LinkList<T>::LinkListNode::LinkListNode() : value_(), next_(nullptr) {}
/// 节点的构造函数
/// \tparam T 链表的类型
/// \param data 传入一个值用于初始化节点的 value_
template <typename T>
LinkList<T>::LinkListNode::LinkListNode(const T &data)
    : value_(data), next_(nullptr) {}
/// 清空函数，用于清空链表中的节点，会保留一个头节点
/// \tparam T 链表的类型
template <typename T>
void LinkList<T>::clean() {
  LinkListNode *p1, *p2;
  // 都从头节点开始
  p1 = p2 = this->head_;
  // p1领先一步
  p1 = p1->next_;
  // p2作为删除指针，将p1指向的节点标记，让p1移动
  // 然后删除p2，再次判断p1是否为空
  while (p1 != nullptr) {
    p2 = p1;
    p1 = p1->next_;
    delete p2;
  }
  // 保留头指针
  this->head_->next_ = nullptr;
}
/// 打印这个链表，其中打印需要模板类自己定义一个输出流函数
/// \tparam T 链表的类型
template <typename T>
void LinkList<T>::display() const {
  // p指向头
  LinkListNode *p = this->head_;
  // 指向第一个元素
  p = p->next_;
  // 循环遍历，直到p移动到空的位置
  while (p != nullptr) {
    // 使用模板自定义的打印函数，每打印一个都换行
    std::cout << p->value_ << std::endl;
    // 指针偏移
    p = p->next_;
  }
}
/// 通过下标aim来查找值，并通过data返回
/// \throw 可能会出现下标越界
/// \param aim 下标，使用人类语言
/// \param data 引用传值，返回找到的值
/// \return 返回false表示没有找到
template <typename T>
bool LinkList<T>::find(int aim, T &data) const {
  // 大于长度-1，或小于0，都返回空指针
  if (aim > this->getLength() - 1 || aim < 0)
    throw std::out_of_range("this is a Exception, maybe index out of range.");

  // 指向头
  LinkListNode *p = this->head_;
  // 计数器
  int count = 0;
  // 指向第一个
  p = p->next_;
  // 查找第一个元素
  while (p != nullptr) {
    if (count == aim) break;
    count++;
    p = p->next_;
  }
  // 返回该元素，使用传值返回
  return p->value_;
}
/// 插入一个元素，插入成功将返回true，插入失败返回false
/// \throw 可能会出现下标越界
/// \tparam T 链表的类型
/// \param aim 插入的位置，插入后aim上就是该元素
/// \param data 要插入的数据的引用
/// \return 返回插入是否成功
template <typename T>
LinkList<T> &LinkList<T>::insert(int aim, const T &data) {
  // 大于长度，或小于0，都返回false
  if (aim > this->getLength() || aim < 0)
    throw std::out_of_range("this is a Exception, maybe index out of range.");

  // 指向头
  LinkListNode *p = this->head_;
  // 计数器
  int count = 0;
  // p指向待操作的节点的前一位
  while (p != nullptr) {
    if (count == aim) break;
    count++;
    p = p->next_;
  }
  // 使用传入的数据新建一个节点
  auto *node = new LinkListNode(data);
  // p的下下一个节点的地址赋值给node的next属性
  // 使node的下一个是被插入的位置的元素
  node->next_ = p->next_;
  // 然后使p的下一个节点赋值为node的地址
  p->next_ = node;
  // 修改元素个数
  this->setLength(this->getLength()+1);
  return *this;
}
/// 链表的修改函数，传入要位置，修改成什么
/// \tparam T 链表的类型
/// \param aim 修改位置
/// \param data 修改值
/// \return 是否修改成功
template <typename T>
LinkList<T> &LinkList<T>::modify(int aim, const T &data) {
  // 大于长度-1，或小于0，都返回false
  if (aim > this->getLength() - 1 || aim < 0)
    throw std::out_of_range("this is a Exception, maybe index out of range.");

  // 指向头
  LinkListNode *p = this->head_;
  // 指向第一个节点
  p = p->next_;
  // 计数器
  int count = 0;
  // p指向待操作的节点
  while (p != nullptr) {
    if (count == aim) break;
    count++;
    p = p->next_;
  }
  // 修改找到的值
  p->value_ = data;
  return *this;
}
/// 删除函数，按位来删除
/// \tparam T 链表的类型
/// \param aim 要删除的位置
/// \return 是否删除成功
template <typename T>
LinkList<T> &LinkList<T>::remove(int aim) {
  // 大于长度-1，或小于0，都返回false
  if (aim > this->getLength() - 1 || aim < 0)
    throw std::out_of_range("this is a Exception, maybe index out of range.");

  // 指向头
  LinkListNode *p = this->head_;
  // 计数器
  int count = 0;
  // p指向待操作的节点的前一位
  while (p != nullptr) {
    if (count == aim) break;
    count++;
    p = p->next_;
  }
  // 标记p的下一位准备删除
  LinkListNode *rm = p->next_;
  // p的下一位变成下下一位
  p->next_ = p->next_->next_;
  // 释放rm内存
  delete rm;
  // 减少自身元素个数
  this->setLength(this->getLength()-1);
  return *this;
}
/// 查找操作，给定值data去找坐标
/// \tparam T 模板类型
/// \param data 待查找的值，不修改它，所以传了常引用
/// \return 返回人类语言的下标，返回0为没找到
template <typename T>
int LinkList<T>::search(const T &data) const {
  // 指向头
  LinkListNode *p = this->head_;
  // 计数器
  int count = 0;
  // 指向第一个
  p = p->next_;
  // 查找第一个元素
  while (p != nullptr) {
    // 判断值相等
    if (data == p->value_) break;
    count++;
    p = p->next_;
  }
  // 返回该元素，使用传值返回。找不到就返回0
  return count == this->getLength() ? 0 : count;
}
template <typename T>
unsigned LinkList<T>::getLength() const {
  return LengthInterface::getLength();
}
template <typename T>
[[maybe_unused]] void LinkList<T>::setLength(unsigned length) {
  LengthInterface::setLength(length);
}

template <typename T>
bool LinkList<T>::isEmpty() const {
  return this->getLength() == 0;
}
template <typename T>
bool LinkList<T>::isNotEmpty() const {
  return this->getLength() != 0;
}

#endif  // STORE_SYSTEM_LINK_LIST_H
