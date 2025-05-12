#pragma once

#include <string>
using namespace std;

class Task {
    public: 
        Task(string& name, string& desc);
        Task(string& name, string& desc, uint8_t& priority);
        Task(string& name, string& desk, uint32_t& due_date);
        Task(string& name, string& desc, uint8_t& priority, uint32_t& due_date);
        string getName() const;
        void setName(string& name);

};