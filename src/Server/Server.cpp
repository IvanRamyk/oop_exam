//
// Created by ivan on 08.06.20.
//

#include "Server.hpp"

int ip::address::field(int x) const{
    if(x < 0 || x > 3)
        return 0;
    return fields[x];
}

bool ip::operator ==(const ip::address& A, const ip::address& B){
    for(int i = 0; i < 4; i++){
        if(A.field(i) != B.field(i))
            return false;
    }
    return true;
}


bool operator <(const Server& A, const Server& B) {
    if (A.data_center != B.data_center)
        return A.data_center < B.data_center;
    if (A.rack != B.rack)
        return A.rack < B.rack;
    return false;
}

bool operator >(const Server& A, const Server& B) {
    return B < A;
}

bool operator !=(const Server& A, const Server& B) {
    return ! (A == B);
}

bool operator ==(const Server& A, const Server& B) {
    return A.IP == B.IP
            && A.data_center == B.data_center
            && A.rack == B.rack
            && A.company == B.company;
}

int Server::toInt() const {
    std::string hashString = data_center + rack + company;
    const int p = 31;
    const int m = 1e9 + 9;
    int hash_value = 0;
    int p_pow = 1;
    for (char c : hashString) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
