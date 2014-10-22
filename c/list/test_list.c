#include <CUnit/CUnit.h>

#include "list.h"

static list* l = NULL;


// test insert func

int init_insert_suite(void){
	l = newList();
	return 0;
}

int clean_insert_suite(void){
	distory(l);
	return 0;
}

void test_insert(void){
	CU_ASSERT_EQUAL(l->len, 0);
	CU_ASSERT_FALSE(insert(l, 1, 1));
	
	CU_ASSERT_TRUE(insert(l, 0, 0));
	CU_ASSERT_TRUE(insert(l, 1, 1));
	CU_ASSERT_TRUE(insert(l, 2, 2));

	CU_ASSERT_EQUAL(l->len, 3);
	CU_ASSERT_EQUAL(l->head->data, 0);
	CU_ASSERT_EQUAL(l->head->next->data, 1);
	CU_ASSERT_EQUAL(l->head->next->next->data, 2);
	CU_ASSERT_EQUAL(l->head->next->next->next, NULL);
}



/*test del func*/

int init_del_suite(void){
	l = newList();
	int i;
	for(i = 0; i < 5; i++){
		insert(l, i, i);
	}

	return 0;
}

int clean_del_suite(void){
	distory(l);
	return 0;
}

void test_del(void){
	// 0 1 2 3 4
	CU_ASSERT_EQUAL(l->len, 5);

	CU_ASSERT_TRUE(del(l, 0));
	// 1 2 3 4

	CU_ASSERT_EQUAL(l->len, 4);
	CU_ASSERT_EQUAL(l->head->data, 1);

	CU_ASSERT_FALSE(del(l, 4));
	CU_ASSERT_TRUE(del(l, 3))
	// 1 2 3

	CU_ASSERT_EQUAL(l->len, 3);
	CU_ASSERT_TRUE(del(l, 1));
	// 1 3

	CU_ASSERT_EQUAL(l->len, 2);

	CU_ASSERT_EQUAL(l->head->next->data, 3);

}

CU_TestInfo insert_testcase[] = {
	{"test for insert", test_insert},
	CU_TEST_INFO_NULL
};

CU_TestInfo del_testcase[] = {
	{"test for del", test_del},
	CU_TEST_INFO_NULL
};

CU_SuiteInfo suites[] = {
	{"Insert Test Suite", init_insert_suite, clean_insert_suite, insert_testcase},
	{"Del Test Suite", init_del_suite, clean_del_suite, del_testcase},
	CU_SUITE_INFO_NULL
};

int main(){

	if (CUE_SUCCESS == CU_initialize_registry() &&
		CUE_SUCCESS == CU_register_suites(suites)){

		CU_curses_run_tests();

  		CU_cleanup_registry();
  	}

	return CU_get_error();
}
