#include "pch.h"

TEST(QubitInVerticalBasis, Zero) {
	Basis verticalBasis(State(1, 0), State(0, 1), "V");
	EXPECT_EQ(State(1, 0), verticalBasis.getState(0));
}
TEST(QubitInVerticalBasis, One) {
	Basis verticalBasis(State(1, 0), State(0, 1), "V");
	EXPECT_EQ(State(0, 1), verticalBasis.getState(1));
}
TEST(QubitInHorizontalBasis, Zero) {
	Basis horizontalBasis(State(REV2ROOT, -REV2ROOT), State(REV2ROOT, REV2ROOT), "H");
	EXPECT_EQ(State(REV2ROOT, -REV2ROOT), horizontalBasis.getState(0));
}
TEST(QubitInHorizontalBasis, One) {
	Basis horizontalBasis(State(REV2ROOT, -REV2ROOT), State(REV2ROOT, REV2ROOT), "H");
	EXPECT_EQ(State(REV2ROOT, REV2ROOT), horizontalBasis.getState(1));
}


TEST(BitInVerticalBasis, HorizontalFirst) {
	Basis verticalBasis(State(1, 0), State(0, 1), "V");
	Basis horizontalBasis(State(REV2ROOT, -REV2ROOT), State(REV2ROOT, REV2ROOT), "H");
	EXPECT_EQ(0, verticalBasis.getBit(Qubit(State(REV2ROOT, -REV2ROOT), horizontalBasis)));
}
TEST(BitInVerticalBasis, HorizontalSecond) {
	Basis verticalBasis(State(1, 0), State(0, 1), "V");
	Basis horizontalBasis(State(REV2ROOT, -REV2ROOT), State(REV2ROOT, REV2ROOT), "H");
	EXPECT_EQ(1, verticalBasis.getBit(Qubit(State(REV2ROOT, REV2ROOT), horizontalBasis)));
}
TEST(BitInHorizontalBasis, VerticalFirst) {
	Basis horizontalBasis(State(REV2ROOT, -REV2ROOT), State(REV2ROOT, REV2ROOT), "H");
	Basis verticalBasis(State(1, 0), State(0, 1), "V");
	EXPECT_EQ(0, horizontalBasis.getBit(Qubit(State(1, 0), verticalBasis)));
}
TEST(BitInHorizontalBasis, VerticalSecond) {
	Basis horizontalBasis(State(REV2ROOT, -REV2ROOT), State(REV2ROOT, REV2ROOT), "H");
	Basis verticalBasis(State(1, 0), State(0, 1), "V");
	EXPECT_EQ(1, horizontalBasis.getBit(Qubit(State(0, 1), verticalBasis)));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}