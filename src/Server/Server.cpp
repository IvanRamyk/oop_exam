//
// Created by ivan on 08.06.20.
//

#include "Server.hpp"

bool operator==(Server a, Server b){
    return (a.data_center == b.data_center) &&
    		(a.rack == b.rack)
}
