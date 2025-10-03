// Exemplo de consumo de API REST em C++ moderno
// Requer: httplib.h e nlohmann/json.hpp
#include <iostream>
#include "httplib.h"
#include "nlohmann/json.hpp"

int main() {
    httplib::Client cli("https://official-joke-api.appspot.com");
    auto res = cli.Get("/jokes/random");
    if (res && res->status == 200) {
        nlohmann::json joke_json = nlohmann::json::parse(res->body);
        std::cout << "--- Piada do Dia ---" << std::endl;
        std::cout << joke_json["setup"] << std::endl;
        std::cout << joke_json["punchline"] << std::endl;
        std::cout << "--------------------" << std::endl;
    } else {
        std::cout << "Erro ao buscar a piada. Status: " << (res ? res->status : 0) << std::endl;
    }
    return 0;
}
