#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <curl/curl.h> // Need libcurl to send data to PHP

std::string generateShortCode(int length = 6) {
    std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string shortCode = "";
    srand(time(0));
    for (int i = 0; i < length; i++) {
        shortCode += chars[rand() % chars.length()];
    }
    return shortCode;
}

void sendToPHP(std::string longUrl, std::string shortCode) {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    
    if(curl) {
        std::string postFields = "long_url=" + longUrl + "&short_code=" + shortCode;
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/url-shortner/store.php");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

int main() {
    std::string longUrl;
    std::cout << "Enter the long URL: ";
    std::getline(std::cin, longUrl);

    std::string shortCode = generateShortCode();
    sendToPHP(longUrl, shortCode);

    std::cout << "Short URL: http://localhost/url-shortner/redirect.php?code=" << shortCode << std::endl;
    return 0;
}
