#include "polygon_data_provider.hpp"
#include "data_point.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
#include <json.hpp>

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::vector<DataPoint> PolygonDataProvider::fetchData(const std::string& symbol, const std::string& timeframe) {
    std::vector<DataPoint> dataPoints;
    std::string readBuffer;

    // Initialize CURL
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string url = "https://api.polygon.io/v1/historic/" + timeframe + "/" + symbol + "?apiKey=YOUR_API_KEY";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);

        // Parse JSON
        auto jsonData = json::parse(readBuffer);
        for (const auto& item : jsonData["results"]) {
            DataPoint dp;
            dp.timestamp = item["t"];
            dp.open = item["o"];
            dp.high = item["h"];
            dp.low = item["l"];
            dp.close = item["c"];
            dp.volume = item["v"];
            dataPoints.push_back(dp);
        }
    }

    return dataPoints;
}
