#include "routes/routes.hpp"
#include "controllers/UserController.hpp"

void registerRoutes(httplib::Server& server) {
    server.Get("/users", [](const httplib::Request&, httplib::Response& res) {
        res.set_content(UserController::listUsers(), "application/json");
    });

    server.Post("/users", [](const httplib::Request& req, httplib::Response& res) {
        auto [status, body] = UserController::createUser(req.body);
        res.status = status;
        res.set_content(body, "application/json");
    });
}