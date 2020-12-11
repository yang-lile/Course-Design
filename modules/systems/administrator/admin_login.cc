//
// Created by lilua on 2020/12/2.
//

#include "admin_system.h"

void adminLogin() {
  //  LoginSystem loginSystem =
  //  LoginSystem("resource/Admin.txt",loginAim::Admin); loginSystem.login();
  AdminSystem adminSystem = AdminSystem("resource/Admin.txt");
  adminSystem.login();
  // TODO: 进入管理页面
}
