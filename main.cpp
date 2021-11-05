#include <iostream>
#include "Test.h"
#include "square_matrix.h"
#include "rectangular_matrix.h"
#include "identity_matrix.h"
#include "Exception.h"
#define CATCH_CONFIG_RUNNER
#include "C:\src\vcpkg\packages\catch2_x64-windows-static\include\catch2\catch.hpp"

using namespace std;

int main(int argc, char* argv[]) {





	int result = Catch::Session().run(argc, argv);

	return (result < 0xff ? result : 0xff);


}