#pragma once

#include <string>
#include <string_view>

namespace roadmap {

[[nodiscard]] auto greeting(std::string_view name) -> std::string;

}
