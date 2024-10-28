#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "structures.h"

template<typename TypeKey, typename TypeVolume>
class Registry {
    DataBase<TypeKey, TypeVolume> dataBase;
    std::vector<DataBase<TypeKey, TypeVolume>> reg;
    
public:
    
    bool getEmptyVec() {
        return reg.empty();
    }
    
    
    void setAddData(TypeKey _key, TypeVolume _volume) {
        dataBase.setKey(_key);
        dataBase.setVolume(_volume);
        reg.push_back(dataBase);
    }

    void setRemoveData(TypeKey _key) {
        int count(0);
        for(auto it = reg.begin(); it != reg.end();) {
            if (it->getKey() == _key) {
                std::cout << "\t-Element \"" << it->getKey() << " : " << it->getVolume() << "\" is removed.\n";
                it = reg.erase(it);
                count++;
            }
            else {
                it++;
            }   
        }
        if(count == 0) {
            std::cout << "Key \"" << _key << "\" is not found.\n";
        }
    }

    void getPrintData() {
        for(auto it = reg.begin(); it != reg.end(); it++) {
            std::cout << "\t-Key " << it->getKey() << " \tValue " << it->getVolume() << std::endl;
        }
    }

    void getFindData(TypeKey _key) {
        int count(0);
        for(auto it = reg.begin(); it != reg.end(); it++) {
            if(it->getKey() == _key) {
                count++;
                std::cout << "\t-Key " << it->getKey() << "\tValue " << it->getVolume() << std::endl;;
            }
        }
        if(count == 0) {
            std::cout << "Key \"" << _key << "\" is not found.\n"; 
        }
    }

};





































/*


*/