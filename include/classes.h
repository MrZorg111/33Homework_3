#pragma once
#include <iostream>
#include <vector>
#include <string>



template<typename TypeKey, typename TypeVolume>
class Registry {
    TypeKey key;
    TypeVolume volume;
public:
    Registry(){};
    Registry(TypeKey key, TypeVolume volume) : key(key), volume(volume) {};

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

template<typename T1, typename T2>
std::vector<Registry<T1, T2>> reg;