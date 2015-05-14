#pragma once

#include <string>

namespace bunsan{namespace crypto{namespace base64
{
    std::string encode(const std::string &data);
    std::string decode(const std::string &data);
}}}
