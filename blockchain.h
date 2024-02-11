#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"
#include <vector>
#include <memory>

// ブロックチェーンクラスの定義
class Blockchain {
public:
    // コンストラクタ
    Blockchain();

    // ブロックチェーンに新しいブロックを追加する関数
    void AddBlock(Block newBlock);

    // 最後のブロックを取得する関数
    const Block &GetLastBlock() const;

    Block getLastBlock() const; // 最後のブロックを返す関数のプロトタイプ

private:
    uint32_t difficulty; // マイニングの難易度
    std::vector<Block> chain; // ブロックのベクター

    // ブロックチェーンの最初のブロックを生成する関数
    void CreateGenesisBlock();
};

class Block {
public:
    // 他のメンバ関数や変数...

    // ブロックのインデックスを取得するメソッド
    int getIndex() const {
        return index; // 'index' はブロックのインデックスを保持する変数
    }

    // ブロックのハッシュを返すメソッド
    std::string getHash() const {
        // ハッシュ計算ロジックを実装
        return ""; // 仮の返り値
    }

    // 新しいメソッドの追加
    std::string getPreviousHash() const {
        return previousHash; // `previousHash` はブロックの前のハッシュを保持する変数
    }

private:
    int index; // この行を追加
    std::string previousHash; // このプライベートメンバー変数の宣言を追加
    // 他のプライベートメンバー変数
};

#endif // BLOCKCHAIN_H
