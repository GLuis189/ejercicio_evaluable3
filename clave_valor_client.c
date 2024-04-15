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
	int set_value_1_arg1;
	char *set_value_1_arg2;
	int set_value_1_arg3;
	double_array set_value_1_arg4;
	get_value_result  *result_3;
	int get_value_1_arg1;
	int  *result_4;
	int modify_value_1_arg1;
	char *modify_value_1_arg2;
	int modify_value_1_arg3;
	double_array modify_value_1_arg4;
	int  *result_5;
	int delete_key_1_arg1;
	int  *result_6;
	int exist_1_arg1;

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
	result_2 = set_value_1(set_value_1_arg1, set_value_1_arg2, set_value_1_arg3, set_value_1_arg4, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = get_value_1(get_value_1_arg1, clnt);
	if (result_3 == (get_value_result *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = modify_value_1(modify_value_1_arg1, modify_value_1_arg2, modify_value_1_arg3, modify_value_1_arg4, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = delete_key_1(delete_key_1_arg1, clnt);
	if (result_5 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_6 = exist_1(exist_1_arg1, clnt);
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