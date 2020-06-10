//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SERVER_HPP
#define OOP_EXAM_SERVER_HPP



#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <cassert>

namespace ip {
    class address {
        std::vector<int> fields;
    public:

        int field(int x) const;
        explicit address(int value1 = 0, int value2 = 0, int value3 = 0, int value4 = 0) {
            fields = {value1, value2, value3, value4};
        }
        explicit address(std::vector<int> vls) {
            assert(vls.size() == 4 && "Vector must contain 4 fields!");
            fields = {vls[0], vls[1], vls[2], vls[3]};
        }

        friend std::ostream& operator<<(std::ostream& os, const address& IP);
        friend bool operator ==(const address& A, const address& B);
        friend bool operator <(const address& A, const address& B);
        std::string toString();


    };

}

std::vector<int> convertIpToVector(std::string stringIp);

class Server {
public:
    ip::address IP;
    std::string data_center;
    std::string rack;
    std::string company;
    explicit Server(ip::address _IP = ip::address(0,0,0,0), std::string _rack = "", std::string center = "", std::string _company = ""): IP(std::move(_IP)), data_center(center), rack(_rack), company(_company){};
    [[nodiscard]] int toInt() const;
    friend bool operator <(const Server& A, const Server& B);
    friend bool operator >(const Server& A, const Server& B);
    friend bool operator ==(const Server& A, const Server& B);
    friend bool operator !=(const Server& A, const Server& B);
};


#endif //OOP_EXAM_SERVER_HPP
