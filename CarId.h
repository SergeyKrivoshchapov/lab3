#pragma once

#include <unordered_set>
#include <string>
#include <stdexcept>
#include <cctype>

class CarId {
private:
    static std::unordered_set<std::string> car_ids;
    static bool IsDigit(const std::string& id);
public:
    static bool IsValidId(const std::string& id);
    static void ClaimId(const std::string& id);
    static void UnclaimId(const std::string& id);
};

