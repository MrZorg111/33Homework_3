#pragma once

template<typename TypeKey, typename TypeVolume>
struct DataBase {
    TypeKey key;
    TypeVolume volume;
public:
    void setKey(TypeKey _key) {
        this->key = _key;
    }
    void setVolume(TypeVolume _volume) {
        this->volume = _volume;
    }

    TypeKey getKey() {
        return this->key;
    }
    TypeVolume getVolume() {
        return this->volume;
    }
};
