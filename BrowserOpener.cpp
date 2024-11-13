//
//  BrowserOpener.cpp
//  ООП_3353_УшаковЕВ_Лр1
//
//  Created by Егор on 13.11.2024.
//

#include "BrowserOpener.hpp"

void BrowserOpener::showBrowser(int pageid) {
    std::string url = "https://ru.wikipedia.org/w/index.php?curid=" + std::to_string(pageid);
    std::string command = "open " + url;
    system(command.c_str());
}
