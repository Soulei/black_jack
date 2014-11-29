
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "fonctions.h"
#include "val_carte.h"

#include <stdio.h>  // for printf


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }


void test_tirer_carte(void) {
	
    CU_ASSERT(tirer_carte(1)<52);
    CU_ASSERT(tirer_carte(1)>0);
    CU_ASSERT(tirer_carte(2)<52);
    CU_ASSERT(tirer_carte(2)>0);

}
void test_donner_valeur_carte(void) {
	
	CU_ASSERT(donner_valeur_carte(1, tirer_carte(1))<12);
    	CU_ASSERT(donner_valeur_carte(1, tirer_carte(1))>1);
	CU_ASSERT(donner_valeur_carte(2, tirer_carte(2))<12);
	CU_ASSERT(donner_valeur_carte(2, tirer_carte(2))>1);

}


int main ( void )
{
    CU_pSuite pSuite = NULL;
    
       if ( CUE_SUCCESS != CU_initialize_registry() )
        return CU_get_error();

    pSuite = CU_add_suite( "fonction_suite", init_suite, clean_suite );
    if ( NULL == pSuite ) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    

    if ( (NULL == CU_add_test(pSuite, "test tirer_carte", test_tirer_carte)) ||
	(NULL == CU_add_test(pSuite, "test donner_valeur_carte",test_donner_valeur_carte))

		)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    

    CU_basic_run_tests();
    printf("\n");
    printf("\n\n");

    CU_cleanup_registry();
    return CU_get_error();
}
