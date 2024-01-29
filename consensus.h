#ifndef CONSENSUS_H
#define CONSENSUS_H

#include "block.h"

// コンセンサスアルゴリズムに関するクラスとメソッドを定義するファイル

class Consensus {
public:
    // コンストラクタ
    Consensus();

    // デストラクタ
    virtual ~Consensus();

    // 新しいブロックが有効かどうかを検証するメソッド
    virtual bool validateBlock(const Block& block) = 0;

    // ブロックチェーンに新しいブロックを追加する前のコンセンサスプロセスを実行するメソッド
    virtual bool reachConsensus(const Block& newBlock) = 0;

    // コンセンサスアルゴリズムの状態をリセットするメソッド
    virtual void resetState() = 0;
};

#endif // CONSENSUS_H
