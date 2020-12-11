#include "systems/administrator/admin_login.cc"
#include "systems/seller/seller_login.cc"
#include "systems/shopkeeper/shopkeeper_login.cc"
#include "systems/user_select.cc"

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
