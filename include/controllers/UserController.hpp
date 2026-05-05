#pragma once
#include <string>
#include <utility>

class UserController {
public:
    static std::string listUsers();
    static std::pair<int, std::string> createUser(const std::string& body);
};