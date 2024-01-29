#ifndef UTILS_H
#define UTILS_H

#include <string>

// ユーティリティ関数とヘルパー関数を定義するファイル

// ハッシュ値を計算するためのユーティリティ関数
std::string CalculateHash(const std::string& input);

// ランダムな文字列を生成するためのユーティリティ関数
std::string GenerateRandomString(size_t length);

// ヘックス文字列をバイナリデータに変換するためのユーティリティ関数
std::string HexToBytes(const std::string& hex);

// バイナリデータをヘックス文字列に変換するためのユーティリティ関数
std::string BytesToHex(const unsigned char* data, size_t length);

// タイムスタンプを取得するためのユーティリティ関数
long long GetCurrentTimestamp();

#endif // UTILS_H
