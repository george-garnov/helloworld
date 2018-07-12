#include <gtest/gtest.h>

TEST(myTest1, Test1) { 
    ASSERT_EQ(100, 6*6+8*8) << "test_1";
}

TEST(myTest2, Test2) {
    ASSERT_FALSE(true!=false) << "test_2";
}

TEST(XmlQuotingTest, OutputsCData) {
  FAIL() << "XML output: "
            "<?xml encoding=\"utf-8\"><top><![CDATA[cdata text]]></top>";
}

//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}

int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);

  if (argc > 1 && strcmp(argv[1], "--shut_down_xml") == 0) {
    TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_xml_generator());
  }
  testing::Test::RecordProperty("ad_hoc_property", "42");
  return RUN_ALL_TESTS();
}
