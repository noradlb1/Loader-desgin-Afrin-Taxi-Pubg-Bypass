#include <iostream>
#include <fstream>
#include <curl/curl.h>

// توكن البوت الخاص بك ومعرف القناة
const std::string BOT_TOKEN = "6549215026:AAHVrLeyFYt2bQ7PFpUZrFd0apIOht02pY0";
const std::string CHANNEL_ID = "-1001824982496";

// المسار إلى الصورة التي تريد إرسالها
const std::string PHOTO_PATH = "C:\\Users\\.jack\\Pictures\\1.png";

size_t WriteCallback22fffffffffffffffffffffffffff(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void sendPhotoToTelegram() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    // رابط API Telegram لإرسال الصور
    std::string url = "https://api.telegram.org/bot" + BOT_TOKEN + "/sendPhoto";

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        struct curl_httppost* formpost = nullptr;
        struct curl_httppost* lastptr = nullptr;

        // إعداد البيانات لإرسالها
        curl_formadd(&formpost, &lastptr,
            CURLFORM_COPYNAME, "chat_id",
            CURLFORM_COPYCONTENTS, CHANNEL_ID.c_str(),
            CURLFORM_END);

        curl_formadd(&formpost, &lastptr,
            CURLFORM_COPYNAME, "photo",
            CURLFORM_FILE, PHOTO_PATH.c_str(),
            CURLFORM_END);

        // إعداد الـ URL والبيانات
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback22fffffffffffffffffffffffffff);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // تنفيذ الطلب
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            std::cout << "Response: " << readBuffer << std::endl;
        }

        // تنظيف
        curl_easy_cleanup(curl);
        curl_formfree(formpost);
    }
    curl_global_cleanup();
}


