#include "services/UserService.hpp"
#include <nlohmann/json.hpp>
#include <stdexcept>

using json = nlohmann::json;

namespace {
    std::vector<User> users = {
        User(1, "João"),
        User(2, "Maria")
    };

    int nextId = 3;
}

std::vector<User> UserService::getAll() {
    return users;
}

User UserService::create(const std::string& body) {
    json data = jon::parse(body);

    if (!data.contains("name") || !data["name"].is_string()) {
        throw std::runtime_error("Campo 'name' é obrigatório.");
    }

    User user(nextId++, 
            data["name"].get<std::string>());
    users.push_back(user);

    return user;
}