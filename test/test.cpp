#include "pch.h"
#include <sstream>
#include "CppUnitTest.h"
#include "..\ConsoleApplication17\Data.h"
#include "..\ConsoleApplication17\Time.h"
#include "..\ConsoleApplication17\Work.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		
		TEST_METHOD(TestReadDate1)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "25.13.2006" };
				Data data;
				sin >> data;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestReadDate2)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "35.07.2006" };
				Data data;
				sin >> data;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestReadDate3)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "13.11.2025" };
				Data data;
				sin >> data;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestReadDate4)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "13.07" };
				Data data;
				sin >> data;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestReadDate5)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "11,11,2006" };
				Data data;
				sin >> data;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestReadDate6)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "31.11.2006" };
				Data data;
				sin >> data;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(TestReadDate7)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "32.07.2006" };
				Data data;
				sin >> data;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}
		TEST_METHOD(TestReadName1)
		{
			try {
				auto sin = std::istringstream{ "logvinets" };
				string owner;
				sin >> owner;
			}
			catch (std::runtime_error& err) {
				Assert::Fail();
			}

		}
		TEST_METHOD(TestReadName2)
		{
			try {
				auto sin = std::istringstream{ "LOGvinets" };
				string owner;
				sin >> owner;
			}
			catch (std::runtime_error& err) {
				Assert::Fail();
			}

		}
		TEST_METHOD(TestReadName3)
		{
			try {
				auto sin = std::istringstream{ "Log$vinets" };
				string owner;
				sin >> owner;
			}
			catch (std::runtime_error& err) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestReadTime1)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "25:43" };
				Time time;
				sin >> time;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}
		TEST_METHOD(TestReadTime2)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "12:65" };
				Time time;
				sin >> time;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}
		TEST_METHOD(TestReadTime3)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "12.40" };
				Time time;
				sin >> time;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}
		TEST_METHOD(TestReadTime4)
		{
			const auto func = [] {
				auto sin = std::istringstream{ "H2:40" };
				Time time;
				sin >> time;
			};
			Assert::ExpectException<std::runtime_error>(func);
		}
	};
}
