#ifndef JSON_H
#define JSON_H

#include <map>
#include <vector>
#include <string>
#include <initializer_list>

#include "util.hpp"

namespace json {
    enum class json_type {
        json_string,
        json_num,
        json_bool,
        json_list,
        json_object
    };

    class json_util {
        public:
            static json_data read(const char* filename){
                return json_data::parse(readFile(filename));
            }

            static bool write(const char* filename, json_data val){
                return writeFile(filename, val.stringify());

            }

    };

    class json_data {
        public :
            static json_data parse(std::string str);

            std::string stringify();

            json_type type;

        protected :
            std::string s_val;
            double n_val;
            bool b_val;
    };
}

#endif