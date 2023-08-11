// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);

  FibLFSR l3("0000000000000000");
  BOOST_REQUIRE(l3.step() != 1); 
  BOOST_REQUIRE(l3.generate(100) == 0);

  BOOST_REQUIRE(sizeof(l3.generate(100)) == sizeof(int));
  BOOST_REQUIRE(sizeof(l3.step()) == sizeof(int));
  BOOST_REQUIRE(sizeof(l3.generate(100)) == sizeof(l3.step()));
  BOOST_REQUIRE(l2.step() == 1 || l2.step() == 0);
}
