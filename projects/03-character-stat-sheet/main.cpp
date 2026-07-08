#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>

enum class CharacterClass {
    MAGE,
    WARRIOR,
    HEALER,
};

struct Character {
    const std::string name;
    const CharacterClass character_class = {};
    const std::uint16_t health = 0;
    const std::uint16_t mana = 0;
    const std::uint16_t strength = 0;
    const std::uint16_t agility = 0;
    bool alive = true;

    friend std::ostream& operator<<(std::ostream& os, const Character& character) {
        std::string character_class;

        switch (character.character_class) {
            case CharacterClass::MAGE:
                character_class = "Mage";
                break;
            case CharacterClass::WARRIOR:
                character_class = "Warrior";
                break;
            case CharacterClass::HEALER:
                character_class = "Healer";
                break;
            default:
                character_class = "Unknown";
        }

        return os << "char: " << character.name << ", class: " << character_class << ", health: " << character.health
                  << ", mana: " << character.mana << ", strength: " << character.strength
                  << ", agility: " << character.agility << "\n";
    }
};

int main(int argc, char** argv) {
    Character paul{"paul", CharacterClass::MAGE, 10, 10, 10, 10, true};
    Character pierre{"pierre", CharacterClass::WARRIOR, 11, 11, 11, 11, true};
    Character jacques{"jacques", CharacterClass::HEALER, 12, 12, 12, 12, true};

    if (argc != 2) return 1;

    if (argv[1] == paul.name) {
        std::cout << paul;
    } else if (argv[1] == pierre.name) {
        std::cout << pierre;
    } else if (argv[1] == jacques.name) {
        std::cout << jacques;
    } else {
        std::cout << "No character found\n";
        return 1;
    }

    return 0;
}
