////
//// Created by jim on 10/30/23.
////
#include <cstring>
#include "hashing.hpp"
#include <openssl/sha.h>
#include <array>
#include <sstream>
#include <iomanip>

std::string wst::sha256(std::string string) {

    std::array<unsigned char, 32> out_buffer{};

    // I hate this, and will be fixing this; should be fine though
    SHA256(reinterpret_cast<unsigned char*>(string.data()), string.size(), out_buffer.data());
    std::stringstream ss;
    for(int e: out_buffer){
        ss << std::hex << std::setw(2) << std::setfill('0') << e;
    }

    return ss.str();
}
