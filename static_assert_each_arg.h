template <
    template <typename...> class Trait,
    bool b = true,
    typename... TraitArgs,
    typename... Args
>
void static_assert_each_arg(Args...) {
    using swallow = std::initializer_list<int>;
    swallow dummy {
        (
            [] () { static_assert(Trait<Args, TraitArgs...>::value == b, "Assertion failed"); }(),
            0
        )...
    };
}