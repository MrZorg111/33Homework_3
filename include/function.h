#pragma once
#include <iostream>
#include <string>
#include "classes.h"
#include "trable_shooting.h"

enum type_input {
    STRING_INT = 1,
    INT_STRING,
    STRING_DOUBLE,
    STRING_STRING
};
enum user_action {
    ADD = 1,
    REMOVE,
    PRINT,
    FIND
};

int working_with_data() {
    int select_user_action(0);
    std::cout << "Select the desired action: " << std::endl;
    std::cout << "add - add an element with a key = 1\n"
              << "remove - delete all items with the specified key = 2\n"
              << "print - print all the elements with their keys on the screen = 3\n"
              << "find - find all the items by their key = 4\n" 
              << "Exit program = 5" << std::endl;
    try {
        std::cin >> select_user_action;
        check_input(select_user_action);
        std::cout << "\n";
    }
    catch (const std::invalid_argument& x){
        std::cerr << x.what() << std::endl;
    };
    return select_user_action;
}

void interface() {
    int type_user_input(0);
    std::string answer("go");
    bool exit_programm = false, total_exit_programm = false;
    do{
        std::cout << "Select the option you plan to work with: " << std::endl;
        std::cout << "String and int = 1\n" 
                << "Int and String = 2\n"
                << "String and Double = 3\n" 
                << "String and String = 4\n"
                << "Exit programm = 5" << std::endl;
        try {           
            std::cin >> type_user_input;
            check_input(type_user_input);
            std::cout << "\n";
        }
        catch(std::invalid_argument& x){
            std::cerr << x.what() << std::endl;
        };    
    
        switch(type_user_input) {
            case STRING_INT: {
                Registry<std::string, int> registry;
                std::string name("0");
                int age(0);
                
                do {   
                    switch (working_with_data()) {
                        case ADD: {
                        std::cout << "Start entering data in the selected type: " << std::endl;
                        do {
                            std::cout << "\t-Name "; std::cin >> name;
                            std::cout << "\t-Age "; std::cin >> age;
                            registry.setKey(name);  registry.setVolume(age);
                            reg<std::string, int>.push_back(registry);
                            std::cout << "To complete, enter stop, or go to continue.";
                            std::cin >> answer;
                            std::cout << "\n";
                        }while(answer != "stop");
                        break;
                    }
                        case REMOVE: {
                        if (!reg<std::string, int>.empty()) {
                            std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                            std::cin >> name;
                            int count(0);
                            for(auto it = reg<std::string, int>.begin(); it != reg<std::string, int>.end();) {
                                if (it->getKey() == name) {
                                    std::cout << "\t-Element \"" << it->getKey() << " : " << it->getVolume() << "\" is removed.\n";
                                    it = reg<std::string, int>.erase(it);
                                    count++;
                                }
                                else {
                                    it++;
                                }   
                            }
                            if(count == 0) {
                                std::cout << "Key \"" << name << "\" is not found.\n";
                            }
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case PRINT: {
                        if(!reg<std::string, int>.empty()) {
                            std::cout << "Currently stored files in the database:" << std::endl;
                            for(auto it = reg<std::string, int>.begin(); it != reg<std::string, int>.end(); it++) {
                                std::cout << "\t-Name " << it->getKey() << " \tAge " << it->getVolume() << std::endl;
                            }
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case FIND: {
                            if(!reg<std::string, int>.empty()) {
                                std::string name("0");
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> name;
                                std::cout << std::endl;
                                int count(0);
                                for(auto it = reg<std::string, int>.begin(); it != reg<std::string, int>.end(); it++) {
                                    if(it->getKey() == name) {
                                        count++;
                                        std::cout << "\t-Name " << it->getKey() << "\tAge " << it->getVolume() << std::endl;;
                                    }
                                }
                                if(count == 0) {
                                    std::cout << "Key \"" << name << "\" is not found.\n"; 
                                }
                                std::cout << "\n";
                                break;
                            }
                            else {
                                std::cout << "Database is empty!\n" << std::endl;
                            }
                            break;
                        }
                        default: {
                            std::cout << "menu! " << std::endl;
                            exit_programm = true;
                            break;
                        }
                    }
                }while(!exit_programm);
                break;
            }
            case INT_STRING: {
                Registry<int, std::string> registry;
                int age(0);
                std::string name("0");
                
                do{   
                    switch (working_with_data()) {
                        case ADD: {
                            std::cout << "Start entering data in the selected type: " << std::endl;
                            do {
                                std::cout << "\t-Age "; std::cin >> age;
                                std::cout << "\t-Name "; std::cin >> name;
                                registry.setKey(age);  registry.setVolume(name);
                                reg<int, std::string>.push_back(registry);
                                std::cout << "To complete, enter stop, or go to continue.";
                                std::cin >> answer;
                                std::cout << "\n";
                            }while(answer != "stop");
                            break;
                        }
                        case REMOVE: {
                            if (!reg<int, std::string>.empty()) {
                                std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                                std::cin >> age;
                                int count(0);
                                for(auto it = reg<int, std::string>.begin(); it != reg<int, std::string>.end();) {
                                    if (it->getKey() == age) {
                                        std::cout << "\t-Element \"" << it->getKey() << " : " << it->getVolume() << "\" is removed.\n";
                                        it = reg<int, std::string>.erase(it);
                                        count++;
                                    }
                                    else {
                                        it++;
                                    }   
                                }
                                if(count == 0) {
                                    std::cout << "Key \"" << age << "\" is not found.\n";
                                }
                            }
                            else {
                                std::cout << "Database is empty!" << std::endl;
                            }
                            std::cout << "\n";
                            break;
                        }
                        case PRINT: {
                            if(!reg<int, std::string>.empty()) {
                                std::cout << "Currently stored files in the database:" << std::endl;
                                for(auto it = reg<int, std::string>.begin(); it != reg<int, std::string>.end(); it++) {
                                    std::cout << "\t-Age " << it->getKey() << " \tName " << it->getVolume() << std::endl;
                                }
                            }
                            else {
                                std::cout << "Database is empty!" << std::endl;
                            }
                            std::cout << "\n";
                            break;
                        }
                        case FIND: {
                            if(!reg<int, std::string>.empty()){
                                int age(0);
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> age;
                                std::cout << std::endl;
                                int count(0);
                                for(auto it = reg<int, std::string>.begin(); it != reg<int, std::string>.end(); it++) {
                                    if(it->getKey() == age) {
                                        count++;
                                        std::cout << "\t-Age " << it->getKey() << " \tName " << it->getVolume();
                                    }
                                }
                                if(count == 0) {
                                    std::cout << "Key \"" << age << "\" is not found.\n"; 
                                }
                                std::cout << "\n";
                                break;
                            }
                            else {
                                std::cout << "Database is empty!\n" << std::endl;
                            }    
                            break;
                        }
                        default: {
                            std::cout << "menu! " << std::endl;
                            exit_programm = true;
                            break;
                        }
                    }
                }while(!exit_programm);
                break;
            }
            case STRING_DOUBLE: {
                Registry<std::string, double> registry;
                double age(0);
                std::string name("0");
                
                do{   
                    switch (working_with_data()) {
                        case ADD: {
                        std::cout << "Start entering data in the selected type: " << std::endl;
                        do {
                            std::cout << "\t-Name "; std::cin >> name;
                            std::cout << "\t-Age "; std::cin >> age;
                            registry.setKey(name);  registry.setVolume(age);
                            reg<std::string, double>.push_back(registry);
                            std::cout << "To complete, enter stop, or go to continue.";
                            std::cin >> answer;
                            std::cout << "\n";
                        }while(answer != "stop");
                        break;
                        }
                        case REMOVE: {
                        if (!reg<std::string, double>.empty()) {
                            std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                            std::cin >> name;
                            int count(0);
                            for(auto it = reg<std::string, double>.begin(); it != reg<std::string, double>.end();) {
                                if (it->getKey() == name) {
                                    std::cout << "\t-Element \"" << it->getKey() << " : " << it->getVolume() << "\" is removed.\n";
                                    it = reg<std::string, double>.erase(it);
                                    count++;
                                }
                                else {
                                    it++;
                                }   
                            }
                            if(count == 0) {
                                std::cout << "Key \"" << name << "\" is not found.\n";
                            }
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case PRINT: {
                        if(!reg<std::string, double>.empty()) {
                            std::cout << "Currently stored files in the database:" << std::endl;
                            for(auto it = reg<std::string, double>.begin(); it != reg<std::string, double>.end(); it++) {
                                std::cout << "\t-Name " << it->getKey() << " \tAge " << it->getVolume() << std::endl;
                            }
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case FIND: {
                            if(!reg<std::string, double>.empty()) {
                                int age(0);
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> name;
                                std::cout << std::endl;
                                int count(0);
                                for(auto it = reg<std::string, double>.begin(); it != reg<std::string, double>.end(); it++) {
                                    if(it->getKey() == name) {
                                        std::cout << "\t-Name " << it->getKey() << " \tAge " << it->getVolume();
                                        count++;
                                    }
                                }
                                if(count == 0) {
                                    std::cout << "Key \"" << name << "\" is not found.\n"; 
                                }
                                std::cout << "\n";
                                break;
                            }
                            else {
                                std::cout << "Database is empty!\n" << std::endl;
                            }
                            break;
                        }
                        default: {
                            std::cout << "menu! " << std::endl;
                            exit_programm = true;
                            break;
                        }
                    }
                }while(!exit_programm);
                break;
            }
            case STRING_STRING: {
                Registry<std::string, std::string> registry;
                std::string name("0"), age("0");
                
                do{   
                    switch (working_with_data()) {
                        case ADD: {
                        std::cout << "Start entering data in the selected type: " << std::endl;
                        do {
                            std::cout << "\t-Name "; std::cin >> name;
                            std::cout << "\t-Age "; std::cin >> age;
                            registry.setKey(name);  registry.setVolume(age);
                            reg<std::string, std::string>.push_back(registry);
                            std::cout << "To complete, enter stop, or go to continue.";
                            std::cin >> answer;
                            std::cout << "\n";
                        }while(answer != "stop");
                        break;
                        }
                        case REMOVE: {
                        if (!reg<std::string, std::string>.empty()) {
                            std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                            std::cin >> name;
                            int count(0);
                            for(auto it = reg<std::string, std::string>.begin(); it != reg<std::string, std::string>.end();) {
                                if (it->getKey() == name) {
                                    std::cout << "\t-Element \"" << it->getKey() << " : " << it->getVolume() << "\" is removed.\n";
                                    it = reg<std::string, std::string>.erase(it);
                                    count++;
                                }
                                else {
                                    it++;
                                }   
                            }
                            if(count == 0) {
                                std::cout << "Key \"" << name << "\" is not found.\n";
                            }
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case PRINT: {
                        if(!reg<std::string, std::string>.empty()) {
                            std::cout << "Currently stored files in the database:" << std::endl;
                            for(auto it = reg<std::string, std::string>.begin(); it != reg<std::string, std::string>.end(); it++) {
                                std::cout << "\t-Name " << it->getKey() << " \tAge " << it->getVolume() << std::endl;
                            }
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case FIND: {
                            if(!reg<std::string, std::string>.empty()) {
                                std::string name("0");
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> name;
                                std::cout << std::endl;
                                int count(0);
                                for(auto it = reg<std::string, std::string>.begin(); it != reg<std::string, std::string>.end(); it++) {
                                    if(it->getKey() == name) {
                                        std::cout << "\t-Name " << it->getKey() << " \tAge " << it->getVolume() << std::endl;;
                                        count++;
                                    }
                                }
                                if(count == 0) {
                                    std::cout << "Key \"" << name << "\" is not found.\n"; 
                                }
                                std::cout << "\n";
                                break;
                            }
                            else {
                                std::cout << "Database is empty!\n" << std::endl;
                            }
                            break;
                        }
                        default: {
                            std::cout << "menu! " << std::endl;
                            exit_programm = true;
                            break;
                        }
                    }
                }while(!exit_programm);
                break;
            }
            default: {
                std::cout << "programm!" << std::endl;
                total_exit_programm = true;
                break;
            }
        }
    }while(!total_exit_programm);
}