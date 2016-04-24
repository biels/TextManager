/*
 * main.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: Biel
 */
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  //Invoke test running
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
