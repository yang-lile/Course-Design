//
// Created by lilua on 2020/12/9.
//

#ifndef STORE_SYSTEM_LINK_LIST_TCC
#define STORE_SYSTEM_LINK_LIST_TCC

#include <iostream>

//#include "link_list.h"

/// 可使用的模板的类型
//template class LinkList<int>;

/// 链表的构造函数
/// \tparam T 链表的类型
template <class T>
LinkList<T>::LinkList() : head_(nullptr) {
  head_ = new LinkListNode();
  head_->value_ = nullptr;
  head_->next_ = nullptr;
}
/// 链表的析构函数
/// \tparam T 链表的类型
template <typename T>
LinkList<T>::~LinkList() {
  // 释放所有的有值节点
  this->clean();
  // 释放头节点
  delete this->head_;
}
/// 节点的构造函数
/// \tparam T 链表的类型
template <typename T>
LinkList<T>::LinkListNode::LinkListNode() : value_(nullptr), next_(nullptr) {}
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
  this->head_->next = nullptr;
}
/// 打印这个链表，其中打印需要模板类自己定义一个输出流函数
/// \tparam T 链表的类型
template <typename T>
void LinkList<T>::display() {
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

// OutputTemplate::pleaseInput("find index","the index need in List");
/// 链表的查找函数
/// 如果返回了空指针 nullptr 证明访问的位置出了问题，找不到该位置的值
/// \tparam T
/// \param aim
/// \return
template <typename T>
T LinkList<T>::find(int aim) const{
  // 大于长度-1，或小于0，都返回空指针
  if (aim > this->getLength() - 1 || aim < 0) return ;

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
/// \tparam T 链表的类型
/// \param data 要插入的数据的引用
/// \param aim 插入的位置，插入后aim上就是该元素
/// \return 返回插入是否成功
template <typename T>
bool LinkList<T>::insert(int aim, T data) {
  // 大于长度，或小于0，都返回false
  if (aim > this->getLength() || aim < 0) return false;

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
  return true;
}
/// 链表的修改函数，传入要位置，修改成什么
/// \tparam T 链表的类型
/// \param aim 修改位置
/// \param data 修改值
/// \return 是否修改成功
template <typename T>
bool LinkList<T>::modify(int aim, T data) {
  // 大于长度-1，或小于0，都返回false
  if (aim > this->getLength() - 1 || aim < 0) return false;

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
  return true;
}
/// 删除函数，按位来删除，如果不在这个范围内就返回删除失败 return false
/// \tparam T 链表的类型
/// \param aim 要删除的位置
/// \return 是否删除成功
template <typename T>
bool LinkList<T>::remove(int aim) {
  // 大于长度-1，或小于0，都返回false
  if (aim > this->getLength() - 1 || aim < 0) return false;

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
  return true;
}
/// 链表的搜索函数，按值从后往前查找，返回第一个找到的值的下标，如果找不到就返回-1
/// \tparam T
/// \param data
/// \return
template <typename T>
int LinkList<T>::search(T data) {
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
  // 返回该元素，使用传值返回。找不到就返回-1
  return count == this->getLength() ? -1 : count;
}

#endif  // STORE_SYSTEM_LINK_LIST_TCC
