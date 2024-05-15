#include "config.h"

config* gConfig;

config::config(const char* filename) : filename(filename) {
    if (std::filesystem::exists(filename)) {
        std::ifstream file(filename);
        file >> data;
        file.close();
    }
    else {
        data["delay"] = 1;
        save();
    }
}

bool config::save() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file << std::setw(4) << data;

    file.close();
    return true;
}
