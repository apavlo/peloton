//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// session_context.h
//
// Identification: src/include/common/session_context.h
//
// Copyright (c) 2015-2018, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include <string>

#include "common/printable.h"

namespace peloton {

// Forward Declaration
class Printable;

/**
 *
 */
class SessionContext : public Printable {
  SessionContext(SessionContext const &) = delete;

 public:

  SessionContext(
      std::string current_database,
      std::string temp_namespace) :
      current_database_(current_database),
      temp_namespace_(temp_namespace) { }

  std::string GetCurrentDatabaseName() const {
    return (current_database_);
  }

  std::string GetTempSessionName() const {
    return (temp_namespace_);
  }

  const std::string GetInfo() const {
    std::ostringstream os;

    os << "SessionContext("
       << "current_database='" << current_database_ << "', "
       << "temp_namespace='" << temp_namespace_ << "'"
       << ")";

    return (os.str());
  }


 private:

  /**
   * The name of the database that this session is connected to
   */
  std::string current_database_;

  /**
   * The name of the namespace where this session will store any
   * temporary database objects (e.g., tables) that it creates.
   */
  std::string temp_namespace_;
};

}  // namespace peloton
