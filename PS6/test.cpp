// Copyright [2023] Hunter Hasenfus

#define BOOST_TEST_MODULE RandWriterTest
#include <boost/test/included/unit_test.hpp>
#include "./RandWriter.h"

BOOST_AUTO_TEST_SUITE(RandWriterTest)
BOOST_AUTO_TEST_CASE(test1) {
    RandWriter rw("abc", 1);
    BOOST_REQUIRE_THROW(rw.freq("ab"), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(test2) {
    RandWriter rw("abc", 1);
    BOOST_REQUIRE_THROW(rw.freq("ab", 'c'), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(test3) {
    RandWriter rw("abc", 2);
    BOOST_REQUIRE_THROW(rw.freq("xy"), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(test4) {
    RandWriter rw("abc", 2);
    BOOST_REQUIRE_THROW(rw.freq("xy", 'c'), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(test5) {
    RandWriter rw("abc", 1);
    BOOST_REQUIRE_THROW(rw.generate("x", 1), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(test6) {
    RandWriter rw("abc", 1);
    BOOST_REQUIRE_THROW(rw.generate("ab", 2), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(test7) {
    RandWriter rw("abc", 0);
    BOOST_REQUIRE_EQUAL(rw.orderK(), 0);
}
BOOST_AUTO_TEST_CASE(test8) {
    RandWriter rw("abc", 1);
    BOOST_REQUIRE_EQUAL(rw.kRand("a"), 'b');
}
BOOST_AUTO_TEST_CASE(test9) {
    RandWriter rw("abc", 0);
    BOOST_REQUIRE_EQUAL(rw.freq(""), 3);
}
BOOST_AUTO_TEST_SUITE_END()
