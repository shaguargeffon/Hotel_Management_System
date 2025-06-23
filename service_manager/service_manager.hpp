#pragma once


#include <tuple>
#include <utility>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <memory>
#include <cxxabi.h>
#include "service.hpp"


// Helper function to demangle type names
std::string demangle(const char* mangled_name) {
    std::size_t len = 0;
    int status = 0;
    std::unique_ptr<char, decltype(&std::free)> ptr(
        __cxxabiv1::__cxa_demangle(mangled_name, nullptr, &len, &status),
        &std::free
    );
    return ptr.get() ? ptr.get() : "demangle error";
}

// Template function to print type name
template<typename T>
void print_type_name(const T& value) {
    std::cout << "Type: " << demangle(typeid(value).name()) << std::endl;
}



template<typename... Ts>
class ServiceManager {
private:
    // Store instances in a tuple
    std::tuple<Ts...> instances_;

public:
    // Default constructor - creates default instances
    constexpr ServiceManager() 
        : instances_(Ts{}...) {}

    // Constructor with arguments
    template<typename... Args>
    constexpr ServiceManager(Args&&... args)
        : instances_(std::forward<Args>(args)...) {}

    // Get reference to instance at compile-time index
    template<std::size_t Index>
    constexpr auto& getInstance() {
        return std::get<Index>(instances_);
    }

    // Get const reference to instance at compile-time index
    template<std::size_t Index>
    constexpr const auto& getInstance() const {
        return std::get<Index>(instances_);
    }

    // Get instance by type
    template<typename T>
    constexpr auto& getInstance() {
        return std::get<T>(instances_);
    }

    // Get const instance by type
    template<typename T>
    constexpr const auto& getInstance() const {
        return std::get<T>(instances_);
    }
};



