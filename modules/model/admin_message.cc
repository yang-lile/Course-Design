//
// Created by lilua on 2020/12/3.
//

#include "admin_message.h"

AdminMessage::AdminMessage() : UserMessage() {}

AdminMessage::AdminMessage(const FixedString &id, const FixedString &pw)
    : UserMessage(id, pw) {}

std::ostream &operator<<(std::ostream &output, AdminMessage &message) {
  output << message.id_ << std::endl << message.password_;
  return output;
}

std::istream &operator>>(std::istream &input, AdminMessage &message) {
  input >> message.id_;
  input >> message.password_;
  return input;
}

bool AdminMessage::operator==(AdminMessage &message) {
  return UserMessage::operator==(message);
}
