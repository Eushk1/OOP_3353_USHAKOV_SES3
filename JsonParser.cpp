//
//  JsonParser.cpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#include "JsonParser.hpp"

std::vector<Response> JsonParser::parseResponse(const std::string& responseString) {
    std::vector<Response> results;
    json jsonData = json::parse(responseString);

    if (jsonData.contains("query") && jsonData["query"].contains("search")) {
        for (const auto& item : jsonData["query"]["search"]) {
            Response response_temp(item["title"], item["pageid"]);
            results.push_back(response_temp);
        }
    } else {
        std::cout << "Блок 'search' не найден." << std::endl;
    }

    return results;
}
