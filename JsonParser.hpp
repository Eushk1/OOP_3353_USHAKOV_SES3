//
//  JsonParser.hpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#ifndef JsonParser_hpp
#define JsonParser_hpp



#include <vector>
#include <string>
#include <iostream>
#include "iParser.hpp" // Предполагается, что у вас есть интерфейс IParser в этом файле
#include <nlohmann/json.hpp> // Для работы с JSON

using json = nlohmann::json;

class JsonParser : public IParser {
public:
    std::vector<Response> parseResponse(const std::string& responseString) override;
};


#endif /* JsonParser_hpp */
