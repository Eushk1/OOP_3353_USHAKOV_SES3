#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <iomanip>
#include <sstream>
#include <nlohmann/json.hpp>
#include <cstdlib>
#include "Response.hpp"
#include "iApi.hpp"
#include "WikiAPi.hpp"
#include "iParser.hpp"
#include "JsonParser.hpp"
#include "BrowserOpener.hpp"

using json = nlohmann::json;



int main() {
    std::unique_ptr<IApi> wikiApi = std::make_unique<WikiApi>();
    std::unique_ptr<IParser> parser = std::make_unique<JsonParser>();
    BrowserOpener browserOpener;

    std::string request = wikiApi->getRequest();
    std::string response = wikiApi->getWikiResponse(request);
    std::vector<Response> parsedResponses = parser->parseResponse(response);

    for (size_t i = 0; i < parsedResponses.size(); i++) {
        std::cout << i << ") " << parsedResponses[i].title << " " << parsedResponses[i].pageid << std::endl;
    }
    
    int selectedOption = wikiApi->getRequestOption(static_cast<int>(parsedResponses.size()));
   // std::cout << "Вы выбрали вариант: " << selectedOption << std::endl;

    if (!parsedResponses.empty()) {
        browserOpener.showBrowser(parsedResponses[selectedOption].pageid);
    }

    return 0;
}
