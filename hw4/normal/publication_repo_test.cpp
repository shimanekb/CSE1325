#include <string>
#include "catch.hpp"
#include "publication_repo.h"

TEST_CASE("publications can be checkedout") {
   PublicationRepo repo;
   const std::string kIsbn = "1234";
   const std::string kName = "Bob";
   const std::string kPhone = "800-431-9555";

   REQUIRE(repo.add_publication(Publication{kIsbn, "Title", "Author", 
               2016, Publication::Genre::FICTION, Publication::TargetAge::ADULT,
               Publication::MediaType::BOOK}) == true); 
   REQUIRE(repo.get_publications().size() == 1);

   SECTION("checking out available publication") {
       REQUIRE(repo.get_publications().at(0).is_checked_out() == false);
       REQUIRE(repo.CheckoutPublication(kIsbn, kName, kPhone) == true);
       REQUIRE(repo.get_publications().at(0).is_checked_out() == true);
       REQUIRE(repo.get_publications().at(0).get_customer_name() == kName);
       REQUIRE(repo.get_publications().at(0).get_customer_phone() == kPhone);
   }

   SECTION("attempting to check out an unavailable publication") {
       REQUIRE(repo.CheckoutPublication(kIsbn, kName, kPhone) == true);
       REQUIRE(repo.get_publications().at(0).is_checked_out() == true);
       //checking out again
       REQUIRE(repo.CheckoutPublication(kIsbn, kName, kPhone) == false);
   }

   SECTION("attempting to check out a non-existent publication") {
       REQUIRE(repo.CheckoutPublication("DNE", kName, kPhone) == false);
   }
}

TEST_CASE("publications can be checkedin") {
   PublicationRepo repo;
   const std::string kIsbn = "1234";
   const std::string kName = "Bob";
   const std::string kPhone = "800-431-9555";

   REQUIRE(repo.add_publication(Publication{kIsbn, "Title", "Author", 
               2016, Publication::Genre::FICTION, Publication::TargetAge::ADULT,
               Publication::MediaType::BOOK}) == true); 
   REQUIRE(repo.get_publications().size() == 1);

   SECTION("checking in a checked out publication") {
       REQUIRE(repo.CheckoutPublication(kIsbn, kName, kPhone) == true);
       REQUIRE(repo.CheckinPublication(kIsbn) == true);
       REQUIRE(repo.get_publications().at(0).is_checked_out() == false);
   }

   SECTION("attempting to check in a currently checked in publication") {
       REQUIRE(repo.CheckinPublication(kIsbn) == false);
   }

   SECTION("attempting to check in a non-existent publication") {
       REQUIRE(repo.CheckinPublication("DNE") == false);
   }
}

TEST_CASE("publications isbns can be validated for uniqueness") {
   PublicationRepo repo;
   const std::string kIsbn = "1234";
   const std::string kName = "Bob";
   const std::string kPhone = "800-431-9555";

   SECTION("initial publications have a unique isbn as a given") {
       REQUIRE(repo.IsIsbnValidUnique(kIsbn) == true);
   }

   SECTION("isbn unique invoked with preexisting isbn") {
       REQUIRE(repo.add_publication(Publication{kIsbn, "Title", "Author", 
               2016, Publication::Genre::FICTION, Publication::TargetAge::ADULT,
               Publication::MediaType::BOOK}) == true); 
       REQUIRE(repo.IsIsbnValidUnique(kIsbn) == false);
   }
}
