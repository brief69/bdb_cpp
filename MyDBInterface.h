#ifndef MY_DB_INTERFACE_H
#define MY_DB_INTERFACE_H

#include "db_interface.h"

class MyDBInterface : public DBInterface {
public:
    MyDBInterface() {}
    virtual ~MyDBInterface() {}
    // DBInterfaceの純粋仮想関数の実装
    void connect() {
        // 実装の詳細
    }
    // 他の必要な関数も同様に実装
};

#endif // MY_DB_INTERFACE_H