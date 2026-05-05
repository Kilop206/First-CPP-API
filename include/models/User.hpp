#pragma once
#include <string>
#include <nlohmann/json.hpp>

class User {
    public:
        int id;
        std::string name;

        User();
        User(int id, std::string name);

        nlohmann::json toJson() const;
}