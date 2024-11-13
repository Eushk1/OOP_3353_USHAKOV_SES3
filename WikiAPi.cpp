//
//  WikiAPi.cpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#include "WikiAPi.hpp"

std::string WikiApi::getRequest() {
    std::string input;
    std::cout << "Введите данные: ";
    std::getline(std::cin, input);
    return input;
}

int WikiApi::getRequestOption(int max) {
    int option;
    std::cout << "Выбери куда переходим: " << std::endl;
    std::cin >> option;
    while (true) {
        
        if (option >= 1 && option < max) {
            break; //
        } else {
            std::cout << "Пожалуйста, введите число от 1 до "<<max << std::endl;
            std::cin >> option;
        }
    }

    return option; 
}

std::string WikiApi::percentEncode(const std::string& str) {
    std::ostringstream escaped;
    escaped << std::hex << std::setfill('0');
    for (unsigned char c : str) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
        } else {
            escaped << '%' << std::setw(2) << static_cast<int>(c);
        }
    }
    return escaped.str();
}

std::string WikiApi::getWikiResponse(const std::string& request) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        std::string encodedRequest = percentEncode(request);
        std::string url = "https://ru.wikipedia.org/w/api.php?action=query&list=search&utf8=&format=json&srsearch=\"" + encodedRequest + "\"";

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

size_t WikiApi::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}
