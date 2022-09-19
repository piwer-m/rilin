#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace ril {
	std::vector<std::string> split(std::string s, std::string del) {
		std::vector<std::string> ret = {};

        auto start = 0U;
        auto end = s.find(del);

        while (end != std::string::npos)
        {
            ret.push_back(s.substr(start, end - start));
            start = end + del.length();
            end = s.find(del, start);
        }

        ret.push_back(s.substr(start, end));

        return ret;
	}

    bool startwith(std::string s, std::string sw) {
        if (s.find(sw, 0) == 0) {
            return true;
        } else {
            return false;
        }
    }

    std::vector<std::string> getArgs(std::string s) {
        std::vector<std::string> ret = split(s, " ");

        std::string args = "";
        for (int i = 1; i < int(ret.size()); i++) {
            args += ret.at(i) + " ";
        }

        return split(args, ",");
    }
}