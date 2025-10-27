#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/point.hpp"

TEST_CASE("Point class Test") {
    Point zero(0,0);

    SECTION("Zero point distance to itself") {
        REQUIRE((zero - zero) == 0.0);
        REQUIRE(zero == zero);
        REQUIRE_FALSE(zero != zero);
    }

    Point one(2,0);

    SECTION("Distance and midpoint") {
        REQUIRE((zero - one) == 2.0);
        Point mid = zero / one;
        REQUIRE(mid.xCoord == 1.0);
        REQUIRE(mid.yCoord == 0.0);
    }

    SECTION("Distance and Midpoint"){
    Point m1(0,0);
    Point m2(3,4);

        REQUIRE((m1 - m2) == 5.0);
        Point mid = m1 / m2;
        REQUIRE(mid.xCoord == 1.5);
        REQUIRE(mid.yCoord == 2.0);
    }

    SECTION("Multiply point by constant") {
        Point p(2,3);
        Point result = p * 2;
        REQUIRE(result.xCoord == 4);
        REQUIRE(result.yCoord == 6);

        result = p * 1;
        REQUIRE(result.xCoord == 2);
        REQUIRE(result.yCoord == 3);
    }

    SECTION("Access coordinates with operator[]") {
        Point p(5,7);
        REQUIRE(p['x'] == 5);
        REQUIRE(p['y'] == 7);
    }

    SECTION("operator<< outputs correct string") {
        Point p(1,2);
        std::stringstream ss;
        ss << p;
        REQUIRE(ss.str() == "(1, 2)");
    }
}
