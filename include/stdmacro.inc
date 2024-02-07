; stdmacro.inc

; 'macro MACRO_NAME { ... }' - a macro that does not produce macros
; 'macro __MACRO_NAME__ { ... }' - a macro that produces macros

macro __TYPE__ __typename, __data_mnemonic, __align {
    struc __typename [__value] \{
    \common
    if ~ __align eq
        align __align
    end if
    if __value eq
        . __data_mnemonic ?
    else
        . __data_mnemonic __value
    end if
    \}
}

macro STRUCT __name {
virtual at 0
    __name __name
end virtual
}

struc ARRAY __typename, __size, __value, [__values] {
common
    __vc = 0
forward
    __vc = __vc + 1
common
if ~ __values eq
    if ~ __size = __vc + 1
        'error: sizeof(' __value, __values ') !=' __size
    end if
    . __typename __value, __values
else if ~ __value eq
    . __typename __size dup(__value)
else
    . __typename __size dup(?)
end if
}

macro __ENUM__ __typename, __enum_name, [__value_name] {
common
    struc __enum_name __value \{
    if __value eq
        . __typename
    else if ~ __value in <__value_name>
        'error: no value' __value 'in' __value_name
    else
        . __typename __enum_name#.\#__value
    end if
    \}
    __vc = 0
forward
    __enum_name#.#__value_name = __vc
    __vc = __vc + 1
}
