#include "utils/JsonResponse.hpp"

std::string JsonResponse::success(const nlhomann::json& data) {
    return data.dump();
}

std::string JsonResponse::error(const std::string& message) {
    return nlohmann::json{
        {"error", message}
    }.dump();
}