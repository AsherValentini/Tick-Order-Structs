# Day 1 – Tick & Order Structs with Strong Types

## 1. Mission Brief (Why this matters)

Real-time trading systems move millions of “ticks” and “orders” per second. A single mis-typed field (e.g., a double where an int64_t µprice was expected) can introduce latency, rounding error, or—worst—send a fat-fingered order. Day 1 lays the foundation for the entire 90-day track by baking type-safety, memory layout discipline, and copy-avoidance into the very first two data objects every other module will touch.

## 2. Functional Spec

| Struct  | Mandatory Fields                                                                                          | Strong-Type Suggestions                                                                                        | Notes                                                              |
| ------- | --------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------ |
| `Tick`  | `InstrumentId id`, `int64_t ts_ns`, `Price px`, `Qty qty`                                                 | *Define wrapper types:*<br>`using InstrumentId = uint32_t` wrapped in a `struct InstrumentId { uint32_t v; };` | Timestamp **nanoseconds since epoch** (monotonic clock OK in sim). |
| `Order` | `OrderId oid`, `InstrumentId id`, `Side side`, `Price px`, `Qty qty`, `TimeInForce tif`, `OrderType type` | `enum class Side { Buy, Sell };` etc.                                                                          | Keep size ≤ 64 bytes; plan for cache-line friendliness.            |

Extras (optional but recommended)

-    Flags bitfield (e.g., IOC, PostOnly).

-    uint8_t venue if you’ll simulate multiple exchanges later.

-    constexpr helper factories: MarketOrder(), LimitOrder(px).

## 3. Design Constraints & Quality Bar

-    No implicit conversions – wrap primitives in tiny structs or enum class to prevent price ↔ qty mix-ups.

-    POD-like – trivially copyable, no virtuals, defaulted =/≠ deleted constructors.

-    Explicit byte size check – static_assert(sizeof(Tick) <= 32, "Tick too large");.

-    Obs-ready – overload ostream<< or provide a to_string() for quick logging.

-    Compile-time guarantees – use static_assert for enum counts (e.g., SideCount==2).

## 4. Deliverables
| File                        | Contents                                                                           |
| --------------------------- | ---------------------------------------------------------------------------------- |
| `tick.hpp / tick.cpp`       | Definition + helper inline functions.                                              |
| `order.hpp / order.cpp`     | Definition + helper inline functions.                                              |
| `strong_types.hpp`          | Tiny wrappers (`Price`, `Qty`, etc.) with `constexpr` ops & explicit constructors. |
| `tests/tick_order_test.cpp` | GoogleTest covering construction, equality, stream output, size.                   |
| `CMakeLists.txt`            | Compiles as static lib + test binary (`make && ctest`).                            |

## 5. Suggested Workflow

-    Prototype strong types first — prove you can add two Price objects but not mix Price with Qty.

-    Layout audit — compile with -Wpadded -Werror to catch accidental padding.

-    Valgrind / -fsanitize=memory smoke — even though these are PODs, start good habits now.

-    Performance micro-check — sizeof, alignof, and a dummy loop that copies them 10 M times; ensure no surprises.

## 6. Acceptance Checklist

-   All static asserts pass; structs meet byte-size budget.

-   clang-tidy / cpp-lint shows 0 critical findings.

-   Unit tests green under AddressSanitizer & UBSan.

-   operator<< prints JSON-ish line in ≤ 80 chars.

-    make clean && make -j$(nproc) succeeds in ≤ 5 s on modest laptop.

## 7. Going Further (Stretch Goals)

-    Add SIMD-friendly packing ([[gnu::packed]]) and benchmark.

-    Implement a constexpr parser: string → Tick for offline log-replay.

-    Provide hash specializations (std::hash<OrderId> etc.) for upcoming unordered-containers.

## 8. What’s Next

Day 2: Build TickQueue<T>—a bounded, thread-safe blocking queue. Your Day 1 structs will flow through it, so tight size/layout today directly translates to queue throughput tomorrow.

Good luck—ship clean, ship fast!
