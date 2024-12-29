#include <string>
#include <map>

class CarSpecs {
private:
    std::map<std::string, std::string> attributes;

public:
    void SetAttribute(const std::string& key, const std::string& value) {
        attributes[key] = value;
    }

    std::string GetAttribute(const std::string& key) const {
        auto it = attributes.find(key);
        return (it != attributes.end()) ? it->second : "";
    }

    bool Matches(const CarSpecs& query) const {
        for (const auto& [key, value] : query.attributes) {
            if (attributes.at(key) != value) {
                return false;
            }
        }
        return true;
    }
};

#include <vector>

class AutoTrader {
private:
    std::vector<CarSpecs> current_cars_vec;

public:
    void LoadDatabase() {
        // Fill current_cars_vec with car specs
    }

    bool search_match(const CarSpecs& query_car) {
        for (const auto& available_car : current_cars_vec) {
            if (available_car.Matches(query_car)) {
                return true;
            }
        }
        return false;
    }
};
