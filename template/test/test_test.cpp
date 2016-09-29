#include "test.h"
#include "catch.hpp"

TEST_CASE("publications can be checkedout") {
   Test test = Test{};
   REQUIRE(test.returnOne() == 1);
}
