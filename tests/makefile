# Detecting OS
UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC=g++-4.8
    GTEST_LL=-I /usr/local/opt/gtest/include/ -lgtest_main -lpthread
else
    ifeq ($(UNAME_S),Darwin)
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/opt/gtest/lib/ -lgtest_main -lgtest -lpthread
    else
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/lib/ -lgtest_main -lgtest -lpthread
    endif
endif

#makefile for intersectiontest
GTEST_CPPFLAGS = -Wall -g -I$(HEADER_DIR) -I$(SRC_DIR) -Wextra -pthread -std=gnu++0x
all:mergesortest mergesortest2 mergesortest3
mergesortest:merge_sort_test.cpp  
	$(CC) $(GTEST_CPPFLAGS) $^ $(GTEST_LL) -o $@


#makefile for intersectiontest
mergesortest2:merge_sort_test_2.cpp  
	$(CC) $(GTEST_CPPFLAGS) $^ $(GTEST_LL) -o $@

mergesortest3:merge_sort_test_3.cpp  
	$(CC) $(GTEST_CPPFLAGS) $^ $(GTEST_LL) -o $@
