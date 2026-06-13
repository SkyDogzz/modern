#include "roadmap/example.hpp"

namespace roadmap {

auto greeting(std::string_view name) -> std::string {
    return "Hello, " + std::string{name};
}

}
