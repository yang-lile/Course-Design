//
// Created by lilua on 2020/12/2.
//

#include "user_message.h"

UserMessage::UserMessage() : id_(), password_() {}

UserMessage::UserMessage(const FixedString& id, const FixedString& passwd)
    : id_(id), password_(passwd) {}

bool UserMessage::operator==(UserMessage& message) {
  if (message.id_ == this->id_ && message.password_ == this->password_)
    return true;
  else
    return false;
}

std::istream& operator>>(std::istream& input, UserMessage& message) {
  input >> message.id_;
  input >> message.password_;
  return input;
}

std::ostream& operator<<(std::ostream& output, UserMessage& message) {
  output << message.id_ << std::endl << message.password_;
  return output;
}

//UserMessage& UserMessage::operator=(const UserMessage& userMessage) = default;

//[[maybe_unused]] UserMessage::UserMessage(const UserMessage& userMessage) {
//  this->id_ = userMessage.id_;
//  this->password_ = userMessage.password_;
//}
