	public class UsaComplexo
	{
		public static void main(String[] Args)
		{
			NumComplexo primeiro = new NumComplexo(1, 2);
			NumComplexo segundo = new NumComplexo (3, 4);
			NumComplexo terceiro = new NumComplexo();
			 
			primeiro.Soma(segundo);
			primeiro.Multiplica(segundo);
			primeiro.Divisao(segundo);
			primeiro.Subtrai(primeiro);
		}
	
	}