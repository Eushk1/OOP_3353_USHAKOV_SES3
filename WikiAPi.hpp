//
//  WikiAPi.hpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#ifndef WikiAPi_hpp
#define WikiAPi_hpp


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <curl/curl.h>
#include "iApi.hpp"

class WikiApi : public IApi {
public:
    std::string getRequest() override;
    int getRequestOption(int max) override;
    std::string getWikiResponse(const std::string& request) override;

private:
    std::string percentEncode(const std::string& str);
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);
};


#endif /* WikiAPi_hpp */
