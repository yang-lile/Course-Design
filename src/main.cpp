#include "pages/administrator/admin_login.cc"
#include "pages/seller/seller_login.cc"
#include "pages/shopkeeper/shopkeeper_login.cc"
#include "pages/user_select.cc"
#include "tools/output_template.h"

int main() {
  OutputTemplate::welcome(OutputTemplate::welcomeState::MainPage);
  while (true) {
    LoginResult result = userSelect();
    switch (result) {
      case ADMINISTRATOR:
        adminLogin();
        break;
      case SHOPKEEPER:
        shopkeeperLogin();
        break;
      case SELLER:
        sellerLogin();
        break;
      case EXIT:
        OutputTemplate::exit();
        return 0;
    }
  }
}
