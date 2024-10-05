#pragma once

#include <filesystem>

namespace Sandbox {

    namespace Utils {
        uint32_t* LoadImageBuffer(const std::filesystem::path& path, uint32_t& outWidth, uint32_t& outHeight);
    }

}