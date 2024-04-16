/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "clave_valor.h"


void
clave_valor_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	int  *result_2;
	value_args set_value_1_arg1;
	get_value_result  *result_3;
	int get_value_1_key;
	int  *result_4;
	value_args modify_value_1_arg1;
	int  *result_5;
	int delete_key_1_key;
	int  *result_6;
	int exist_1_key;

#ifndef	DEBUG
	clnt = clnt_create (host, CLAVE_VALOR, CLAVE_VALOR_V1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = init_1(clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	set_value_1_arg1.key = 1;
	set_value_1_arg1.value1 = "Hola\0";
	set_value_1_arg1.N_value2 = 3;
	set_value_1_arg1.V_value2.double_array_len = 3;
	set_value_1_arg1.V_value2.double_array_val = (double *)malloc(3 * sizeof(double));
	set_value_1_arg1.V_value2.double_array_val[0] = 1.0;
	set_value_1_arg1.V_value2.double_array_val[1] = 2.0;
	set_value_1_arg1.V_value2.double_array_val[2] = 3.0;
	result_2 = set_value_1(set_value_1_arg1, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	set_value_1_arg1.key = 2;
	set_value_1_arg1.value1 = "Hola 2\0";
	set_value_1_arg1.N_value2 = 3;
	set_value_1_arg1.V_value2.double_array_len = 3;
	set_value_1_arg1.V_value2.double_array_val = (double *)malloc(3 * sizeof(double));
	set_value_1_arg1.V_value2.double_array_val[0] = 1.0;
	set_value_1_arg1.V_value2.double_array_val[1] = 2.0;
	set_value_1_arg1.V_value2.double_array_val[2] = 3.0;
	result_2 = set_value_1(set_value_1_arg1, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	get_value_1_key = 1;
	result_3 = get_value_1(get_value_1_key, clnt);
	if (result_3 == (get_value_result *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf(result_3->status == 0 ? "Valor: %s\n" : "No existe la clave\n", result_3->value1);
	printf("Vector: ");
	for (int i = 0; i < result_3->N_value2; i++)
	{
		printf("%f ", result_3->V_value2.double_array_val[i]);
	}
	printf("\n");
	modify_value_1_arg1.key = 1;
	modify_value_1_arg1.value1 = "Adios\0";
	modify_value_1_arg1.N_value2 = 3;
	modify_value_1_arg1.V_value2.double_array_len = 3;
	modify_value_1_arg1.V_value2.double_array_val = (double *)malloc(3 * sizeof(double));
	modify_value_1_arg1.V_value2.double_array_val[0] = 4.0;
	modify_value_1_arg1.V_value2.double_array_val[1] = 5.0;
	modify_value_1_arg1.V_value2.double_array_val[2] = 6.0;
	result_4 = modify_value_1(modify_value_1_arg1, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	delete_key_1_key = 1;
	result_5 = delete_key_1(delete_key_1_key, clnt);
	if (result_5 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	exist_1_key = 2;
	result_6 = exist_1(exist_1_key, clnt);
	if (result_6 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	clave_valor_1 (host);
exit (0);
}