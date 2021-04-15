#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "heap.h"
#include <iostream>

TEST_CASE("Constructor") {
    HeapTree t;
}

TEST_CASE("Destructor") {
    HeapTree *t = new HeapTree;
    delete t;
}

TEST_CASE("Min-Heap") {
    SUBCASE("Empty"){
        HeapTree t;
        REQUIRE(t.isComplete() == true);
    }

    SUBCASE("Complete") {
        HeapTree t;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);
        REQUIRE(t.isComplete() == true);
    }

    SUBCASE("Order"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);
        t.preorder(oss);
        REQUIRE(oss.str() == "2, 3, 5, 4, 6, 7, 8, \n");
    }
}

TEST_CASE("Find last"){
    SUBCASE("Full - Right Right Child"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);
        t.find_last(oss);
        REQUIRE(oss.str() == "8\n");
    }

    SUBCASE("Complete - Right Left Child"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.find_last(oss);
        REQUIRE(oss.str() == "7\n");
    }

    SUBCASE("Complete - Left Right Child"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.find_last(oss);
        REQUIRE(oss.str() == "6\n");
    }

    SUBCASE("Complete - Left Left Child"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(2);
        t.insert(4);
        t.find_last(oss);
        REQUIRE(oss.str() == "5\n");
    }
}

TEST_CASE("Remove Min"){
    SUBCASE("Remove once"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.remove_min();

        t.preorder(oss);
        REQUIRE(oss.str() == "3, 4, 8, 5, 6, 7, \n");
    }

    SUBCASE("Remove twice"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.remove_min();
        t.remove_min();

        t.preorder(oss);
        REQUIRE(oss.str() == "4, 5, 8, 7, 6, \n");
    }

    SUBCASE("Remove thrice"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.remove_min();
        t.remove_min();
        t.remove_min();

        t.preorder(oss);
        REQUIRE(oss.str() == "5, 7, 8, 6, \n");
    }
}

TEST_CASE("Delete Element"){
    SUBCASE("Remove last"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.delete_element(8);

        t.preorder(oss);
        REQUIRE(oss.str() == "2, 3, 5, 4, 6, 7, \n");
    }

    SUBCASE("Remove first"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.delete_element(2);

        t.preorder(oss);
        REQUIRE(oss.str() == "3, 4, 8, 5, 6, 7, \n");
    }

    SUBCASE("Remove middle"){
        HeapTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.delete_element(3);

        t.preorder(oss);
        REQUIRE(oss.str() == "2, 4, 8, 5, 6, 7, \n");
    }
}