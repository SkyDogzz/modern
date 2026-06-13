# Project 20 Ownership Mechanics Sequence

This scaffold replaces the former standalone Projects 20-22. It is one diagnosis,
repair, and refactor sequence.

1. Write tests that expose the defects in `broken_buffer.hpp`.
2. Repair destruction and deep-copy behavior.
3. Use the allocation failpoint to test strong copy assignment.
4. Add move operations with a documented post-move state.
5. Observe relocation in `std::vector`.
6. Replace the manual owner in the client model with `std::vector<std::byte>`.
7. Delete unnecessary special members from the final client type.

Keep the raw-owner implementation as a teaching artifact. The final production-style
artifact is the Rule-of-Zero client.
