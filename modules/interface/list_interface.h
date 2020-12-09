//
// Created by lilua on 2020/12/10.
//

#ifndef STORE_SYSTEM_LIST_INTERFACE_H
#define STORE_SYSTEM_LIST_INTERFACE_H

#include "clean_interface.h"
#include "display_interface.h"
#include "empty_interface.h"
#include "find_interface.h"
#include "insert_interface.h"
#include "length_interface.h"
#include "modify_interface.h"
#include "remove_interface.h"
#include "search_interface.h"

template <typename T>
class [[maybe_unused]] ListInterface : public CleanInterface,
                      public DisplayInterface,
                      public EmptyInterface,
                      public FindInterface<T>,
                      public InsertInterface<T>,
                      public LengthInterface,
                      public ModifyInterface<T>,
                      public RemoveInterface<T>,
                      public SearchInterface<T>
{
  
};

#endif  // STORE_SYSTEM_LIST_INTERFACE_H
