/* SCDM - A simple standard for managing program data
 * Copyright (C) 2020 Spencer Smith
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifndef SCDM_H
#define SCDM_H

namespace sc
{
    struct Flag
    {
        std::string   key;
        std::string   value;
        Flag(std::string k="", std::string v=0);
        void          set_key(std::string k)   { key = k; }
        void          set_value(std::string v) { value = v; }
    };
    struct DM
    {
        DM();
        static std::vector<Flag*>       flags;
        static void                   parse(std::string const& s, const char d, std::vector<std::string>& o1, std::vector<std::string>& o2);
        static void                   add_flag(std::string k, std::string v=0);
        static void                   update_flag(std::string k, std::string v=0);
        static std::string            view_flags();
        static void                   load_flags(std::string sf);
        static void                   save_flags(std::string sf);
    };
}
#endif
