#include "pages/administrator/admin_login.cc"
#include "pages/seller/seller_login.cc"
#include "pages/shopkeeper/shopkeeper_login.cc"
#include "pages/user_select.cc"

int main() {
  outputTemplate::welcome();
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
        outputTemplate::exit();
        return 0;
    }
  }
}
