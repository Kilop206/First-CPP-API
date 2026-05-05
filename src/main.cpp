#include <httplib.h>
#include "routes/Routes.hpp"

int main() {
    httplib::Server server;

    registerRoutes(server);

    std::cout << "Servidor rodando em http://localhost:8080\n";
    server.listen("0.0.0.0", 8080);

    return 0;
}