#include "Test.h"
#include <iostream>
#include <iomanip>

bool test::Test::s_succes = 1;
uint32_t test::Test::s_test_count = 1;

test::Test::Test(const char* name, bool(*func)())
{
	m_name = name;
	m_func = func;
}

bool test::Test::runTest()
{
	m_begin = std::chrono::system_clock::now();
	const bool curretTestResult = m_func();
	m_end = std::chrono::system_clock::now();

	if (!curretTestResult)
		s_succes = 0;

	const auto testNumber = s_test_count++;
	const float time = getElapsedTimeMilliseconds();
	std::cout << testNumber << ". ";
	test::printResult(10, ((curretTestResult) ? "OK" : "FAIL"));
	std::cout.setf(std::ios::left);
	std::cout.unsetf(std::ios::right);
	std::cout << " " << std::setw(30) << getName()  << " | Time: " << std::setprecision(2) << std::setiosflags(std::ios::scientific) << std::fixed << time << "ms." << std::endl;

	return curretTestResult;
}

const char* test::Test::getName() const
{
	return m_name;
}

const uint64_t test::Test::getElapsedTimeSeconds() const
{
	return std::chrono::duration_cast<std::chrono::seconds>(m_end - m_begin).count();
}

const uint64_t test::Test::getElapsedTimeMilliseconds() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_begin).count();
}

const uint64_t test::Test::getElapsedTimeMicroseconds() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(m_end - m_begin).count();
}

const uint64_t test::Test::getElapsedTimeMinutes() const
{
	return std::chrono::duration_cast<std::chrono::minutes>(m_end - m_begin).count();
}



#include <iomanip>

void test::printResult(uint32_t len, const char* str)
{
	uint32_t res = len - strlen(str);
	std::cout << std::setw(res / 2) << std::setiosflags(std::ios::left) << std::resetiosflags(std::ios::right) << "[";
	std::cout << str;
	std::cout << std::setw(res / 2) << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right) << "]";
}
