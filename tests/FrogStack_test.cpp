#include "../src/FrogStack.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/dish.hpp"

FrogStack<Dish> Dish_Stack_test;
Dish one_dish("A dish with one fish pattern on it");
Dish two_dish("A dish with two fish patterns on it");
Dish red_dish("A dish with a red fish pattern on it");
Dish blue_dish("A dish with a blue fish pattern on it");

TEST_CASE(" a stack is initialized with size 0") {
    REQUIRE(Dish_Stack_test.mySize() == 0);
}

TEST_CASE( "a Dish Stack can have dishes put into it and have its size tracked" ) {
    Dish_Stack_test.push(one_dish);
    REQUIRE(Dish_Stack_test.mySize() == 1);
    Dish_Stack_test.push(two_dish);
    REQUIRE(Dish_Stack_test.mySize() == 2);
    Dish_Stack_test.push(red_dish);
    REQUIRE(Dish_Stack_test.mySize() == 3);
    Dish_Stack_test.push(blue_dish);
    REQUIRE(Dish_Stack_test.mySize() == 4);

    // peek works
    Dish peeked_dish = Dish_Stack_test.peek();
    REQUIRE(peeked_dish.get_description() == "A dish with a blue fish pattern on it");

    // pop works
    Dish popped_dish = Dish_Stack_test.pop();
    REQUIRE(popped_dish.get_description() == "A dish with a blue fish pattern on it");

    // pop works, again
    Dish another_popped_dish = Dish_Stack_test.pop();
    REQUIRE(another_popped_dish.get_description() == "A dish with a red fish pattern on it");

    // size is tracked
    REQUIRE(Dish_Stack_test.mySize() == 2);

    // clear works
    Dish_Stack_test.clear();
    REQUIRE(Dish_Stack_test.mySize() == 0);

    // it can then get a new dish
    Dish_Stack_test.push(blue_dish);
    REQUIRE(Dish_Stack_test.mySize() == 1);
}

TEST_CASE( "a stack can be made with other objects" ) {
    FrogStack<bool> Bool_Stack_test;
    REQUIRE(Bool_Stack_test.mySize() == 0);
    Bool_Stack_test.push(true);
    REQUIRE(Bool_Stack_test.mySize() == 1);
    Bool_Stack_test.push(false);
    REQUIRE(Bool_Stack_test.mySize() == 2);
    Bool_Stack_test.push(true);
    REQUIRE(Bool_Stack_test.mySize() == 3);
    Bool_Stack_test.push(true);
    REQUIRE(Bool_Stack_test.mySize() == 4);
    Bool_Stack_test.push(true);
    REQUIRE(Bool_Stack_test.mySize() == 5);
    Bool_Stack_test.push(false);
    REQUIRE(Bool_Stack_test.mySize() == 6);

    // then you can pop the values
    Bool_Stack_test.pop();
    REQUIRE(Bool_Stack_test.mySize() == 5);
    Bool_Stack_test.pop();
    REQUIRE(Bool_Stack_test.mySize() == 4);
    Bool_Stack_test.pop();
    REQUIRE(Bool_Stack_test.mySize() == 3);
    Bool_Stack_test.pop();
    REQUIRE(Bool_Stack_test.mySize() == 2);
    Bool_Stack_test.pop();
    REQUIRE(Bool_Stack_test.mySize() == 1);
    Bool_Stack_test.pop();
    REQUIRE(Bool_Stack_test.mySize() == 0);

    // CLEAR WORKS
    Bool_Stack_test.push(false);
    Bool_Stack_test.push(true);
    Bool_Stack_test.push(false);
    Bool_Stack_test.push(false);
    Bool_Stack_test.push(false);
    REQUIRE(Bool_Stack_test.mySize() == 5);

    Bool_Stack_test.clear();
    REQUIRE( Bool_Stack_test.mySize() == 0);

}