//
//  Response.hpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#ifndef Response_hpp
#define Response_hpp

#include <stdio.h>
#include <string>

class Response {
public:
    std::string title;
    int pageid;

    Response(const std::string& t, int p) : title(t), pageid(p) {}
};

#endif /* Response_hpp */
