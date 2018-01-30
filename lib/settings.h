#ifndef PROJECT_SETTINGS_H
#define PROJECT_SETTINGS_H

#include <cereal/types/array.hpp>
#include <cereal/types/vector.hpp>


struct Settings
{
    std::array<uint16_t, 3> dimensions = {10, 10, 10};
    uint32_t bank_number = 16u;
    uint32_t bank_size = 256u;
    std::vector<uint8_t> core_to_mem_map;
    std::vector<size_t> inputs;
    std::vector<size_t> outputs;

    static Settings from_ast(const std::unordered_map<std::string, std::vector<uint8_t>>& ast);

    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(dimensions, bank_number, bank_size, core_to_mem_map, inputs, outputs);
    }
};


#endif //PROJECT_SETTINGS_H
