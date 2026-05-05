#pragma once
#include <vector>
#include <string>
#include "models/User.hpp"

class UserService {
    public:
        static std::vector<User> getAll();
        static User create(const std::string& body);
}