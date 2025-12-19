# Thread-Safe In-Memory Key-Value Store with LRU Eviction

A Redis-inspired, thread-safe in-memory key-value store implemented in modern C++.  
The system provides O(1) average-time GET/SET/DELETE operations and enforces an LRU (Least Recently Used) eviction policy.

This project is intentionally minimal and correctness-focused, designed to demonstrate core systems concepts such as data structure design, concurrency control, and API clarity.

---

## Key Features

- O(1) average-time GET / SET / DELETE
- LRU eviction using hash map + doubly linked list
- Thread-safe access via RAII-based locking
- Clear separation of concerns
- Modern C++17

---

## High-Level Design

The system is composed of two main components:

### 1. LRUCache
Responsible for:
- Managing key-value storage
- Maintaining LRU ordering
- Enforcing capacity-based eviction

This component is **not thread-safe by design**.

### 2. KeyValueStore
A thin, thread-safe wrapper around `LRUCache` that:
- Serializes access using a mutex
- Provides a clean public API
- Encapsulates concurrency concerns

---

## Data Structures

- `std::unordered_map`  
  Used for constant-time key lookup.

- `std::list`  
  Used to maintain LRU ordering with constant-time insert and erase.

---

## Complexity Analysis

| Operation | Time Complexity |
|---------|-----------------|
| GET     | O(1) average    |
| SET     | O(1) average    |
| DELETE  | O(1) average    |

Space complexity is O(N), where N is the configured capacity.

---

## Build & Run

### Requirements
- C++17 compatible compiler (clang++ / g++)

### Build
```bash
make
