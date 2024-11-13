//
//  iApi.hpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#ifndef iApi_hpp
#define iApi_hpp

#include <stdio.h>
#include <string>

class IApi {
public:
    virtual ~IApi() = default;
    virtual std::string getRequest() = 0;
    virtual int getRequestOption(int max) = 0; // Новый метод для выбора варианта
    virtual std::string getWikiResponse(const std::string& request) = 0;
};

#endif /* iApi_hpp */
