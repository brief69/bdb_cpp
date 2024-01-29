#include <openssl/sha.h>
#include <iostream>
#include <sstream>
#include <iomanip>

// ハッシュ値を計算する関数
std::string calculateHash(const std::string& input) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input.c_str(), input.size());
    SHA256_Final(digest, &ctx);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    }

    return ss.str();
}

// 現在のタイムスタンプを取得する関数
long long getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

// 文字列を16進数表記に変換する関数
std::string stringToHex(const std::string& input) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (const auto &c : input) {
        ss << std::setw(2) << static_cast<int>(static_cast<unsigned char>(c));
    }
    return ss.str();
}

// ユーティリティ関数をテストする関数
void testUtilities() {
    // ハッシュ値計算のテスト
    std::string testString = "Hello, Blockchain!";
    std::string hash = calculateHash(testString);
    std::cout << "Hash of '" << testString << "': " << hash << std::endl;

    // タイムスタンプ取得のテスト
    long long timestamp = getCurrentTimestamp();
    std::cout << "Current timestamp: " << timestamp << std::endl;

    // 文字列を16進数に変換するテスト
    std::string hexString = stringToHex(testString);
    std::cout << "Hex of '" << testString << "': " << hexString << std::endl;
}

// メイン関数から呼び出される初期化関数
void initializeUtils() {
    // ユーティリティ関数のテストを行う
    testUtilities();
}
