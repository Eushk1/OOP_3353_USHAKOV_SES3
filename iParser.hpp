//
//  iParser.hpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#ifndef iParser_hpp
#define iParser_hpp

#include <stdio.h>
#include <string>
#include "Response.hpp"

class IParser {
public:
    virtual ~IParser() = default;
    virtual std::vector<Response> parseResponse(const std::string& responseString) = 0;
};

#endif /* iParser_hpp */
