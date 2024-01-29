#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <vector>
#include <string>

// ブロッククラスの定義
class Block {
public:
    // コンストラクタ
    Block(uint32_t indexIn, const std::string &dataIn);

    // ブロックのハッシュを取得する関数
    std::string GetHash() const;

    // ブロックのインデックスを取得する関数
    uint32_t GetIndex() const;

    // ブロックのハッシュを計算する関数
    void MineBlock(uint32_t difficulty);

private:
    uint32_t index; // ブロックのインデックス
    int64_t nonce; // ナンス値
    std::string data; // ブロックに保存されるデータ
    std::string hash; // ブロックのハッシュ値
    time_t timestamp; // タイムスタンプ

    // ブロックのハッシュ値を計算するための関数
    std::string CalculateHash() const;
    std::string prevHash; // 前のブロックのハッシュ値
};

#endif // BLOCK_H
