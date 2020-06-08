//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SERVER_HPP
#define OOP_EXAM_SERVER_HPP

#include <string>
#include <utility>
#include <vector>
#include <iostream>

class Server;
class Rack;

class Company {
public:
    std::string name;
    std::vector<Server *> servers;

    explicit Company(std::string _name) : name(std::move(_name)) {}
};

class DataCenter {
    std::string name;
    std::vector <Rack *> racks;
    explicit DataCenter(std::string _name): name(std::move(_name)) {}
};

class Rack {
public:
    std::string index;
    std::vector <Server * > servers;
    DataCenter * data_center;
    explicit Rack(std::string _index = "", DataCenter * center = nullptr): index(std::move(_index)), data_center(center){}
};

namespace ip {
    class address {
        std::vector<int> fields;
    public:
        explicit address(int value1 = 0, int value2 = 0, int value3 = 0, int value4 = 0) {
            fields = {value1, value2, value3, value4};
        }
        friend std::ostream& operator<<(std::ostream& os, const address& IP);


    };
    std::ostream& operator<<(std::ostream& os, const address& IP)
    {
        os << IP.fields[0] << '.' << IP.fields[1] << '.' << IP.fields[2] << '.' << IP.fields[3];
        return os;
    }
}

class Server {
public:
    ip::address IP;
    int id;
    Rack * rack;
    explicit Server(ip::address _IP, int _id = -1, Rack * _rack = nullptr): IP(std::move(_IP)), id(_id), rack(_rack) {};
};


#endif //OOP_EXAM_SERVER_HPP
