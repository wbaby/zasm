#pragma once

#include <cstdint>
#include <string>
#include <zasm/core/enumflags.hpp>

namespace zasm
{
    class Program;
    class Node;
    class Instruction;
} // namespace zasm

namespace zasm::formatter
{
    namespace detail
    {
        enum class FormatOptions : std::uint32_t
        {
            None = 0,
            HexOffsets = (1U << 0),
            HexImmediates = (1U << 1),
        };
        ZASM_ENABLE_ENUM_OPERATORS(FormatOptions);

    } // namespace detail

    using Options = detail::FormatOptions;

    /// <summary>
    /// Formats the entire program and results the generated text.
    /// </summary>
    /// <param name="program">The program to print as text</param>
    /// <param name="options">Format options</param>
    std::string toString(Program& program, Options options = {});

    /// <summary>
    /// Formats a single node and results the text.
    /// </summary>
    /// <param name="program">The program to print as text</param>
    /// <param name="node">Formats only the specified node</param>
    /// <param name="options">Format options</param>
    std::string toString(Program& program, const Node* node, Options options = {});

    /// <summary>
    /// Formats the specified range, 'to' is not inclusive.
    /// </summary>
    /// <param name="program">The program to print as text</param>
    /// <param name="nodeFrom">First node</param>
    /// <param name="nodeTo">Last node</param>
    /// <param name="options">Format options</param>
    std::string toString(Program& program, const Node* nodeFrom, const Node* nodeTo, Options options = {});

    /// <summary>
    /// Formats a single instruction and results the text.
    /// </summary>
    /// <param name="program">The program to print as text</param>
    /// <param name="instr">Instruction to format</param>
    /// <param name="options">Format options</param>
    std::string toString(Program& program, const Instruction* instr, Options options = {});

} // namespace zasm::formatter
