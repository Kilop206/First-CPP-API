#include "models/User.hpp"

User::User() : id(0), name("") {}

User::User(int id, std::string name)
    : id(id), name(std::move(name)) {}

nlohman::json User::toJson() const {
    return {
        {"id", id},
        {"name", name}
    }
}