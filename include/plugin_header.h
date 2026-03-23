#ifndef PLUGIN_HEADER_H
#define PLUGIN_HEADER_H

// RegisteredScript CRTP base class
template <typename T>
class RegisteredScript {
public:
    static void Register() {
        // Registration logic here
    }
};

// Inline exported function example
inline void ExampleFunction() {
    // Function logic here
}

#endif // PLUGIN_HEADER_H