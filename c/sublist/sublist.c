#include "sublist.h"
#include <stdbool.h>

static bool is_equal(int *list1, int *list2, size_t length){
    for (size_t index = 0; index < length; ++index){
        if (list1[index] != list2[index])
            return false;
    }
    return true;
}

static bool is_sublist(int *list1, int *list2, size_t length1, size_t length2){
    size_t index1 = 0, index2 = 0;
    while (index2 < length2 && index1 < length1){
        if (list2[index2] == list1[index1])
            ++index1;
        else if (index1) {
            index2 -= index1;
            index1 = 0;
        }
        ++index2;
    }
    return index1 == length1;
}

comparison_result_t check_lists(int *list1, int *list2, size_t length1,
                                size_t length2){
    if (length1 == length2){
        if (is_equal(list1, list2, length1))
            return EQUAL;
        else
            return UNEQUAL;
    }

    if (length1 > length2 && is_sublist(list2, list1, length2, length1))
        return SUPERLIST;

    if (length1 < length2 && is_sublist(list1, list2, length1, length2))
        return SUBLIST;

    return UNEQUAL;
}
