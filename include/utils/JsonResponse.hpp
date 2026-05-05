#pragma once
#include <string>
#include <nlohmann/json.hpp>

class JsonResponse {
    public:
        static std::string success(const nlohmann::json& data);
        static std::string error(const std::string& message);
};