#include "clave_valor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>


int init(){
	CLIENT *clnt;
	int  *result_1;

    char *host = getenv("IP_TUPLAS");

	clnt = clnt_create (host, CLAVE_VALOR, CLAVE_VALOR_V1, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

    result_1 = init_1(clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
    
    clnt_destroy (clnt);
    return *result_1;
}

int set_value(int clave, char *valor1, int N_value2, double *V_value2){
    CLIENT *clnt;
    int  *result_2;
    value_args  set_value_1_arg1;

    char *host = getenv("IP_TUPLAS");

    clnt = clnt_create (host, CLAVE_VALOR, CLAVE_VALOR_V1, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }

    set_value_1_arg1.key = clave;
    set_value_1_arg1.value1 = valor1;
    set_value_1_arg1.N_value2 = N_value2;
    set_value_1_arg1.V_value2.double_array_len = N_value2;
    set_value_1_arg1.V_value2.double_array_val = V_value2;

    result_2 = set_value_1(set_value_1_arg1, clnt);
    if (result_2 == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }

    clnt_destroy (clnt);
    return *result_2;
}

int get_value(int key, char *value1, int *N_value2, double *V_value2){
    CLIENT *clnt;
    get_value_result  *result_3;
    int get_value_1_arg1;

    char *host = getenv("IP_TUPLAS");

    clnt = clnt_create (host, CLAVE_VALOR, CLAVE_VALOR_V1, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }

    get_value_1_arg1 = key;

    result_3 = get_value_1(get_value_1_arg1, clnt);
    if (result_3 == (value_args *) NULL) {
        clnt_perror (clnt, "call failed");
    }

    strcpy(value1, result_3->value1);
    *N_value2 = result_3->N_value2;
    for (int i = 0; i < *N_value2; i++){
        V_value2[i] = result_3->V_value2.double_array_val[i];
    }

    clnt_destroy (clnt);
    return result_3->status;
}

int modify_value(int clave, char *valor1, int N_value2, double *V_value2){
    CLIENT *clnt;
    int  *result_4;
    value_args  modify_value_1_arg1;

    char *host = getenv("IP_TUPLAS");

    clnt = clnt_create (host, CLAVE_VALOR, CLAVE_VALOR_V1, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }

    modify_value_1_arg1.key = clave;
    modify_value_1_arg1.value1 = valor1;
    modify_value_1_arg1.N_value2 = N_value2;
    modify_value_1_arg1.V_value2.double_array_len = N_value2;
    modify_value_1_arg1.V_value2.double_array_val = V_value2;

    result_4 = modify_value_1(modify_value_1_arg1, clnt);
    if (result_4 == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }

    clnt_destroy (clnt);
    return *result_4;
}

int delete_key(int clave){
    CLIENT *clnt;
    int  *result_5;
    int delete_key_1_arg1;

    char *host = getenv("IP_TUPLAS");

    clnt = clnt_create (host, CLAVE_VALOR, CLAVE_VALOR_V1, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }

    delete_key_1_arg1 = clave;

    result_5 = delete_key_1(delete_key_1_arg1, clnt);
    if (result_5 == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }

    clnt_destroy (clnt);
    return *result_5;
}

int exist(int clave){
    CLIENT *clnt;
    int  *result_6;
    int exist_1_arg1;

    char *host = getenv("IP_TUPLAS");

    clnt = clnt_create (host, CLAVE_VALOR, CLAVE_VALOR_V1, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }

    exist_1_arg1 = clave;

    result_6 = exist_1(exist_1_arg1, clnt);
    if (result_6 == (int *) NULL) {
        clnt_perror (clnt, "call failed");
    }

    clnt_destroy (clnt);
    return *result_6;
}