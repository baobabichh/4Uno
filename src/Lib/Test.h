#pragma once
#include <chrono>
#include <vector>

#define EXPECTED_TRUE(x) if(!(x))return 0;
#define EXPECTED_FALSE(x) if((x))return 0;

namespace test
{
	class Test
	{
	public:
		Test() = default;
		Test(const char* name, bool(*func)());

		bool runTest();
		const char* getName() const;
		const uint64_t getElapsedTimeSeconds() const;
		const uint64_t getElapsedTimeMilliseconds() const;
		const uint64_t getElapsedTimeMicroseconds() const;
		const uint64_t getElapsedTimeMinutes() const;

	private:
		bool(*m_func)();
		const char* m_name = "NO NAME TEST";
		std::chrono::time_point<std::chrono::system_clock> m_begin;
		std::chrono::time_point<std::chrono::system_clock> m_end;
		static bool s_succes;
		static uint32_t s_test_count;
	};

	void printResult(uint32_t len, const char* str);
}





#define TEST(testName)\
namespace tests\
{\
	bool FUNC_ ## testName();\
	class testName : public test::Test\
	{\
	public:\
		testName() : test::Test( #testName , FUNC_ ## testName) { runTest();  }\
	};\
	namespace\
	{\
		class HOLDER_ ## testName\
		{\
		public:\
			static testName m_test;\
		}; \
		testName   HOLDER_ ## testName::m_test = testName();\
	}\
}\
bool tests::FUNC_ ## testName()\

 