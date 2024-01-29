#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <functional>
#include "block.h"

// ネットワークインターフェースクラスの定義
class NetworkInterface {
public:
    // コンストラクタ
    NetworkInterface();

    // デストラクタ
    virtual ~NetworkInterface();

    // ネットワークへの接続を開始する関数
    virtual void StartServer(const std::string& address, uint16_t port) = 0;

    // ネットワークからの接続を閉じる関数
    virtual void StopServer() = 0;

    // 他のノードに接続する関数
    virtual void ConnectToPeer(const std::string& address, uint16_t port) = 0;

    // 他のノードからの接続を切断する関数
    virtual void DisconnectPeer(const std::string& address, uint16_t port) = 0;

    // ブロックをネットワークにブロードキャストする関数
    virtual void BroadcastBlock(const Block& block) = 0;

    // ブロックを受信した時のコールバック関数を設定する関数
    virtual void OnBlockReceived(std::function<void(const Block&)> callback) = 0;

    // ネットワークエラーが発生した時のコールバック関数を設定する関数
    virtual void OnNetworkError(std::function<void(const std::string&)> callback) = 0;
};

#endif // NETWORK_H
