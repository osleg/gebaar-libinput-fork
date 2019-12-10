/*
    gebaar
    Copyright (C) 2019   coffee2code

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SRC_GEBAAR_CONFIG_H_
#define SRC_GEBAAR_CONFIG_H_

#include <cpptoml.h>
#include <pwd.h>
#include <spdlog/spdlog.h>
#include <filesystem>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <iterator>

#define MAX_DIRECTION 9
#define MIN_DIRECTION 1

const std::map<int, std::string> SWIPE_COMMANDS = {
    {1, "left_up"}, {2, "up"},        {3, "right_up"}, {4, "left"},
    {6, "right"},   {7, "left_down"}, {8, "down"},     {9, "right_down"}};

namespace gebaar::config {
class Config {
   public:
    Config();

    bool loaded = false;

    void load_config();

    struct settings {
        bool pinch_one_shot;
        double pinch_threshold;

        bool swipe_one_shot;
        double swipe_threshold;
        bool swipe_trigger_on_release;
    } settings;

    enum pinch { PINCH_IN, PINCH_OUT };
    std::string pinch_commands[10];
    std::string get_command(int fingers, int swipe_type);

   private:
    bool config_file_exists();

    bool find_config_file();

    std::string config_file_path;
    std::shared_ptr<cpptoml::table> config;
    std::map<int, std::map<std::string, std::string>> commands;
};
}  // namespace gebaar::config
#endif  // SRC_CONFIG_CONFIG_H_
