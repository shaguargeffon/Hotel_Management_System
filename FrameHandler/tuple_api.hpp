#pragma once

#include <tuple>


template<typename Tuple, typename Functor, typename First, typename ... Ts>
constexpr void for_each_tuple_impl(const Tuple& t, Functor &&f) {

    f(std::get<First>(t));
    for_each_tuple_impl<Tuple, Functor, Ts...>(t, std::forward<Functor>(f));
}


template<typename Tuple, typename Functor>
constexpr void for_each_tuple_impl(const Tuple&, Functor&&) {
    return;
}


template<typename Functor, typename ... Ts>
constexpr void for_each_tuple(const std::tuple<Ts...> &t, Functor &&f) {
    for_each_tuple_impl<std::tuple<Ts...>, Functor, Ts...>(t, std::forward<Functor>(f));
}



