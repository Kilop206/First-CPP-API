#include "controllers/UserController.hpp"
#include "services/UserService.hpp"
#include "utils/JsonResponse.hpp"
#include <nlohmann/json.hpp>

std::string UserController::listUsers() {
    auto users = UserService::getAll();

    nlohmann::json result;
    result["users"] = nlohmann::json::array();

    for (const auto& user : users) {
        result["users"].push_back(user.toJson());
    }

    return JsonResponse::success(result);
}

std::pair<int, std::string> UserController::createUser(const std::string& body) {
    try {
        User user = UserService::create(body);

        nlohmann::json result;
        result["message"] = "Usuário criado com sucesso";
        result["user"] = user.toJson();

        return {201, JsonResponse::success(result)};
    } catch (const std::exception& e) {
        return {400, JsonResponse::error(e.what())};
    }
}