//
// Created by ivan on 08.06.20.
//

#include "Server.hpp"

bool operator <(const Server& A, const Server& B) {
    if (A.data_center != B.data_center)
        return A.data_center < B.data_center;
    if (A.rack != B.rack)
        return A.rack < B.rack;
}

bool operator >(const Server& A, const Server& B) {
    return B < A;
}

bool operator !=(const Server& A, const Server& B) {
    return B < A || A < B;
}

bool operator ==(const Server& A, const Server& B) {
    return !(B != A);
}