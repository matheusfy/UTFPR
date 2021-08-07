public class NumComplexo{

	private float real;
	private float img;

		public NumComplexo(float Nreal, float Nimg)
		{
			real = Nreal;
			img = Nimg;
		}

		public NumComplexo()
		{
			real=0;
			img=0;
		}
		public void Inicia(float Nreal, float Nimg)
		{
			real = Nreal;
			img = Nimg;

		}
		public static void Imprime(float real, float img)
		{
			System.out.println(real+"+"+img+"i");
		}
		public boolean Igual(NumComplexo x)
		{
			if(x.real==real && x.img==img)
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		public void Soma(NumComplexo x){
			NumComplexo y = new NumComplexo ();
			y.real = x.real + real;
			y.img = x.img + img;
			real = y.real;
			img = y.img;
			if(img>=0){
			System.out.println(real+"+"+img+"i");
			}
			else
			{
			System.out.println(real+""+img+"i");
			}

			}
		public void Multiplica(NumComplexo x){
			NumComplexo y = new NumComplexo ();
			y.real = (real * x.real) - (img * x.img);
			y.img =  (real * x.img) + ( x.real * img);
			real = y.real;
			img = y.img;

			System.out.println(real+"+"+img+"i");

	}
		public void Divisao(NumComplexo x){
			NumComplexo y = new NumComplexo ();
			y.real = ((real * x.real) + (img * x.img))/((x.real * x.real)+(x.img * x.img));
			y.img =  ((img * x.real) - ( real * x.img))/((x.real * x.real)+(x.img * x.img));
			real = y.real;
			img = y.img;

			System.out.println(real+"+"+img+"i");

	}
		public void Subtrai(NumComplexo x)
		{
			NumComplexo y = new NumComplexo();
			y.real = real - x.real;
			y.img = img - x.img;
			real = y.real;
			img = y.img;

			System.out.println(real+"+"+img+"i");

		}
}
