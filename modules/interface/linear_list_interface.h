//
// Created by lilua on 2020/12/10.
//

#ifndef STORE_SYSTEM_LINEAR_LIST_INTERFACE_H
#define STORE_SYSTEM_LINEAR_LIST_INTERFACE_H

#include "clean_interface.h"
#include "display_interface.h"
#include "empty_interface.h"
#include "find_interface.h"
#include "insert_interface.h"
#include "length_interface.h"
#include "modify_interface.h"
#include "remove_interface.h"
#include "search_interface.h"

template <typename T, template <typename> class ClassT>
class LinearListInterface : public CleanInterface,
                                             public DisplayInterface,
                                             public EmptyInterface,
                                             public FindInterface<T>,
                                             public InsertInterface<T, ClassT>,
                                             public LengthInterface,
                                             public ModifyInterface<T, ClassT>,
                                             public RemoveInterface<T, ClassT>,
                                             public SearchInterface<T> {};

#endif  // STORE_SYSTEM_LINEAR_LIST_INTERFACE_H
