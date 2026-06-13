#pragma once

#include <string>
#include <string_view>

namespace roadmap::linking_lab {

[[nodiscard]] auto make_greeting(std::string_view name) -> std::string;

}
