//
// Created by lilua on 2020/12/2.
//

#include "user_message.h"

UserMessage::UserMessage() : id_(), password_() {}

UserMessage::UserMessage(const FixedString& id, const FixedString& passwd)
    : id_(id), password_(passwd) {}

bool UserMessage::operator==(UserMessage& userMessage) {
  if (userMessage.id_ == this->id_ && userMessage.password_ == this->password_)
    return true;
  else
    return false;
}

std::istream& operator>>(std::istream& input, UserMessage& userMessage) {
  input >> userMessage.id_;
  input >> userMessage.password_;
  return input;
}

std::ostream& operator<<(std::ostream& output, UserMessage& userMessage) {
  output << userMessage.id_ << std::endl << userMessage.password_;
  return output;
}

//UserMessage& UserMessage::operator=(const UserMessage& userMessage) = default;

//[[maybe_unused]] UserMessage::UserMessage(const UserMessage& userMessage) {
//  this->id_ = userMessage.id_;
//  this->password_ = userMessage.password_;
//}
