//#include <iostream>
//#include <curl/curl.h>
//
//// Callback function to write downloaded data to a file
//size_t WriteCallback(void* contents, size_t size, size_t nmemb, FILE* file) {
//    return fwrite(contents, size, nmemb, file);
//}
//
//int main() {
//    CURL* curl;
//    CURLcode res;
//    FILE* file;
//
//    // URL of the file to download
//    const char* url = "http://example.com/file.txt";
//
//    // Local file path to save the downloaded file
//    const char* filepath = "downloaded_file.txt";
//
//    // Initialize curl
//    curl_global_init(CURL_GLOBAL_DEFAULT);
//    curl = curl_easy_init();
//
//    if (curl) {
//        // Open the local file for writing
//        file = fopen(filepath, "wb");
//        if (file) {
//            // Set the URL to download
//            curl_easy_setopt(curl, CURLOPT_URL, url);
//            // Set the write callback function
//            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//            // Set the file to write to
//            curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
//
//            // Perform the download
//            res = curl_easy_perform(curl);
//            if (res != CURLE_OK)
//                std::cerr << "Failed to download the file: " << curl_easy_strerror(res) << std::endl;
//
//            // Close the file
//            fclose(file);
//        }
//        else {
//            std::cerr << "Failed to open the file for writing" << std::endl;
//        }
//
//        // Cleanup curl
//        curl_easy_cleanup(curl);
//    }
//    else {
//        std::cerr << "Failed to initialize curl" << std::endl;
//    }
//
//    // Cleanup curl global state
//    curl_global_cleanup();
//
//    return 0;
//}
