# Project 43 Structural Guidance

Implement the command wrapper in this order:

1. Define the public value semantics: empty state, copyability, movability, and
   invocation.
2. Define a private abstract operation with virtual invocation, cloning, and a
   virtual destructor.
3. Define a private model template that stores one concrete callable and implements
   the abstract operation.
4. Store the abstract operation behind an exclusive owner.
5. Implement copy through cloning and move through normal owner movement.
6. Compare allocation, copying, diagnostics, and interface restrictions with
   `std::function`, `std::move_only_function`, inheritance, and `variant`.

Required tests:

- empty invocation policy;
- copied commands own independent state where the callable is copyable;
- move-only policy if selected;
- exception propagation;
- destruction through the erased interface;
- one command whose type is unknown to the wrapper.

Do not add small-buffer optimization until profiling shows allocation is relevant.
The scaffold deliberately supplies structure but no completed wrapper.
