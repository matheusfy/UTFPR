/* TAD complexo (a,b) */

//tipo exportado
typedef struct complexo *complexo;

//funcoes exportadas

//funcao que aloca memoria e retorna um numero complexo
complexo cria(float a, float b);

//funcao que libera memoria de um numero complexo previamente criado
void libera (complexo c);

//funcao que acessa valores (a,b) de um numero complexo previamente criado
void acessa (complexo c, float* a, float* b);

//funcao que atribui novos valores (a,b) de um numero complexo previamente criado
void atribui (complexo c, float a, float b);

//funcao para calcular o modulo (valor absoluto) de um numero complexo previamente criado
float modulo(complexo c);

//funcao para somar 2 numeros complexos
complexo soma(complexo c1, complexo c2);








