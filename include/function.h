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
                std::string key("0");
                int value(0);
                
                do {   
                    switch (working_with_data()) {
                        case ADD: {
                        std::cout << "Start entering data in the selected type: " << std::endl;
                        do {
                            std::cout << "\t-Key "; std::cin >> key;
                            std::cout << "\t-Value "; std::cin >> value;
                            registry.setAddData(key, value);
                            std::cout << "To complete, enter stop, or go to continue.";
                            std::cin >> answer;
                            std::cout << "\n";
                        }while(answer != "stop");
                        break;
                    }
                        case REMOVE: {
                        if (!registry.getEmptyVec()) {
                            std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                            std::cin >> key;
                            registry.setRemoveData(key);
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case PRINT: {
                        if(!registry.getEmptyVec()) {
                            std::cout << "Currently stored files in the database:" << std::endl;
                            registry.getPrintData();
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case FIND: {
                            if(!registry.getEmptyVec()) {
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> key;
                                std::cout << std::endl;
                                registry.getFindData(key);
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
                int key(0);
                std::string value("0");
                
                do{   
                    switch (working_with_data()) {
                        case ADD: {
                            std::cout << "Start entering data in the selected type: " << std::endl;
                            do {
                                std::cout << "\t-Age "; std::cin >> key;
                                std::cout << "\t-Name "; std::cin >> value;
                                registry.setAddData(key, value);
                                std::cout << "To complete, enter stop, or go to continue.";
                                std::cin >> answer;
                                std::cout << "\n";
                            }while(answer != "stop");
                            break;
                        }
                        case REMOVE: {
                            if (!registry.getEmptyVec()) {
                                std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                                std::cin >> key;
                                registry.setRemoveData(key);
                            }
                            else {
                                std::cout << "Database is empty!" << std::endl;
                            }
                            std::cout << "\n";
                            break;
                        }
                        case PRINT: {
                            if(!registry.getEmptyVec()) {
                                std::cout << "Currently stored files in the database:" << std::endl;
                                registry.getPrintData();
                            }
                            else {
                                std::cout << "Database is empty!" << std::endl;
                            }
                            std::cout << "\n";
                            break;
                        }
                        case FIND: {
                            if(!registry.getEmptyVec()){
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> key;
                                std::cout << std::endl;
                                registry.getFindData(key);
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
                std::string key("0");
                double value(0);
                
                do{   
                    switch (working_with_data()) {
                        case ADD: {
                        std::cout << "Start entering data in the selected type: " << std::endl;
                        do {
                            std::cout << "\t-Key "; std::cin >> key;
                            std::cout << "\t-Value "; std::cin >> value;
                            registry.setAddData(key, value);
                            std::cout << "To complete, enter stop, or go to continue.";
                            std::cin >> answer;
                            std::cout << "\n";
                        }while(answer != "stop");
                        break;
                        }
                        case REMOVE: {
                        if (!registry.getEmptyVec()) {
                            std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                            std::cin >> key;
                            registry.setRemoveData(key);
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case PRINT: {
                        if(!registry.getEmptyVec()) {
                            std::cout << "Currently stored files in the database:" << std::endl;
                            registry.getPrintData();
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case FIND: {
                            if(!registry.getEmptyVec()) {
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> key;
                                std::cout << std::endl;
                                registry.getFindData(key);
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
                std::string key("0"), value("0");
                
                do{   
                    switch (working_with_data()) {
                        case ADD: {
                        std::cout << "Start entering data in the selected type: " << std::endl;
                        do {
                            std::cout << "\t-Key "; std::cin >> key;
                            std::cout << "\t-Value "; std::cin >> value;
                            registry.setAddData(key, value);
                            std::cout << "To complete, enter stop, or go to continue.";
                            std::cin >> answer;
                            std::cout << "\n";
                        }while(answer != "stop");
                        break;
                        }
                        case REMOVE: {
                        if (!registry.getEmptyVec()) {
                            std::cout << "Enter the key for which you want to delete all data: " << std::endl;
                            std::cin >> key;
                            registry.setRemoveData(key);
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case PRINT: {
                        if(!registry.getEmptyVec()) {
                            std::cout << "Currently stored files in the database:" << std::endl;
                            registry.getPrintData();
                        }
                        else {
                            std::cout << "Database is empty!" << std::endl;
                        }
                        std::cout << "\n";
                        break;
                    }
                        case FIND: {
                            if(!registry.getEmptyVec()) {
                                std::cout << "Enter the key to search for all its values: " << std::endl;
                                std::cin >> key;
                                std::cout << std::endl;
                                registry.getFindData(key);
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