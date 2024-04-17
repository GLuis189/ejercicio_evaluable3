/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CLAVE_VALOR_H_RPCGEN
#define _CLAVE_VALOR_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	u_int double_array_len;
	double *double_array_val;
} double_array;

struct value_args {
	int key;
	char *value1;
	int N_value2;
	double_array V_value2;
};
typedef struct value_args value_args;

struct get_value_result {
	int status;
	char *value1;
	int N_value2;
	double_array V_value2;
};
typedef struct get_value_result get_value_result;

#define CLAVE_VALOR 99
#define CLAVE_VALOR_V1 1

#if defined(__STDC__) || defined(__cplusplus)
#define INIT 1
extern  enum clnt_stat init_1(int *, CLIENT *);
extern  bool_t init_1_svc(int *, struct svc_req *);
#define SET_VALUE 2
extern  enum clnt_stat set_value_1(value_args , int *, CLIENT *);
extern  bool_t set_value_1_svc(value_args , int *, struct svc_req *);
#define GET_VALUE 3
extern  enum clnt_stat get_value_1(int , get_value_result *, CLIENT *);
extern  bool_t get_value_1_svc(int , get_value_result *, struct svc_req *);
#define MODIFY_VALUE 4
extern  enum clnt_stat modify_value_1(value_args , int *, CLIENT *);
extern  bool_t modify_value_1_svc(value_args , int *, struct svc_req *);
#define DELETE_KEY 5
extern  enum clnt_stat delete_key_1(int , int *, CLIENT *);
extern  bool_t delete_key_1_svc(int , int *, struct svc_req *);
#define EXIST 6
extern  enum clnt_stat exist_1(int , int *, CLIENT *);
extern  bool_t exist_1_svc(int , int *, struct svc_req *);
extern int clave_valor_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INIT 1
extern  enum clnt_stat init_1();
extern  bool_t init_1_svc();
#define SET_VALUE 2
extern  enum clnt_stat set_value_1();
extern  bool_t set_value_1_svc();
#define GET_VALUE 3
extern  enum clnt_stat get_value_1();
extern  bool_t get_value_1_svc();
#define MODIFY_VALUE 4
extern  enum clnt_stat modify_value_1();
extern  bool_t modify_value_1_svc();
#define DELETE_KEY 5
extern  enum clnt_stat delete_key_1();
extern  bool_t delete_key_1_svc();
#define EXIST 6
extern  enum clnt_stat exist_1();
extern  bool_t exist_1_svc();
extern int clave_valor_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_double_array (XDR *, double_array*);
extern  bool_t xdr_value_args (XDR *, value_args*);
extern  bool_t xdr_get_value_result (XDR *, get_value_result*);

#else /* K&R C */
extern bool_t xdr_double_array ();
extern bool_t xdr_value_args ();
extern bool_t xdr_get_value_result ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CLAVE_VALOR_H_RPCGEN */
