public class Rational
{
        private int a;
        private int b;

        public Rational()
        {
            a = 0;
            b = 1;
        }
        public void Insere(int numerador, int denominador)
        {
            if(denominador != 0){
            a = numerador;
            b = denominador;
            System.out.println(" " + a + "/ " + b);
            }
        }
        public void soma(int numerador, int denominador)
        {
             a = a * denominador + b * numerador;
             b = b * denominador;
             Reduz();
             System.out.println(" " + a + "/ " + b);
        }
        public void subtrai(int numerador, int denominador)
        {
            a = a * denominador - b * numerador;
             b = b * denominador;
             System.out.println(" " + a + "/ " + b);
             Reduz();
        }
        public void multiplica(int numerador, int denominador)
        {
            a = a * numerador;
             b = b * denominador;
            Reduz();
             System.out.println(" " + a + "/ " + b);
        }
        public void divide(int numerador, int denominador)
        {
            a = a * denominador;
            b = b * numerador;
            Reduz();
             System.out.println(" " + a + "/ " + b);
        }
        public void Reduz()
        {

            int i = 0;
            if(a==b)
            {
                a=1;
                b=1;
            }
            else{

		do{
			if( a%b == 0){
				a = a/b;
				b = b/b;
				i=1;
			}
			else if(b%a == 0){
				b = b/a;
				a= a/a;
				i=1;
			}
			else if( a%2 == 0 && b%2 == 0){
				a = a/2;
				b = b/2;
			}
			else{

				i = 1;
			}

		}while( i !=1);
        }
        }
        public void Imprime()
        {
            double x=0;
            x = (double) a / (double) b ;
            System.out.println(" " +x);
        }
}
