#include "vector.hpp"

#define pi 3.14159265

int main(int argc, char const *argv[])
{
	Vector2 vector_1 = Vector2(0, 1);
	Vector2 vector_2 = Vector2(1, 2);
	vector_1 += vector_1;
	vector_2 = vector_1;
	std::cin >> vector_1;
	std::cout << vector_1 << vector_2;
	std::cout << "\n";
	float x = vector_2 ^ vector_1;
	std::cout << x;
	std::cout << "\n";
	std::cout << 3 * vector_1;
	std::cout << "\n";
	std::cout << vector_2 * 3;
	std::cout << "\n";
	vector_1 += vector_2;
	vector_1 -= vector_2;
	std::cout << vector_1.GetNorm();
	std::cout << "\n";
	vector_2.Rotate(pi/2);
	std::cout << vector_2;
	std::cout << "\n";
	std::cout << vector_2.GetRotated(-pi/2);
	std::cout << "\n";
	std::cout << -vector_2;
	std::cout << "\n";
	std::cout << vector_1/2;
	return 0;
}