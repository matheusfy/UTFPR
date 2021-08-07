import java.util.Scanner;
public class MaquinaReal
{
	private MaquinaVirtual[] M = new MaquinaVirtual[5];
	private boolean Estado;
	private float RamT;
	private float Hd;
	private String nome;
	private int numM = 0;
	private int numR = 0; 
	
	public MaquinaReal()
	{	
		this.RamT = 0;
		this.Hd = 0;
		this.Estado = false;
		this.nome = "";
		
		for(int i =0; i<5; i++)
		{
			M[i]= new MaquinaVirtual();
		}
	}
	
	public void CriaReal(float R, float H, String N)
	{	
		this.RamT = R;
		this.Hd = H;
		this.Estado = false;
		this.nome = N;
	}

	public void CriarVirtual(float RamV, float HdV, String nomeV )
	{	
		
		if(numM <5) // Verifica se a espaco disponivel para insercao
		{
			if(numM == -1)
			{
				numM = 0;
			}
			if(RamV < RamT )	 //verificaçao para ver se a Ram da maquina virtual a ser inserida nao e maior que a da Real
			{
				M[numM].CriaVirtual(RamV, HdV , nomeV);
				RamT = RamT - RamV;
				numM++;
			}
			else
			{
			System.out.println("nao e possivel inserir uma MaquinaVirtual deste desempenho");
			}
		} 
		else
		{
			System.out.println("nao e possivel criar mais maquina virtual");
		}
	}

	public void Ligar()
	{	
		Estado = true;
		System.out.println("A maquina foi ligada");
	    
	}

	public void Desligar()
	{	
			int i=0;
			while(i++<5)
			{
			M[i].desligar();
			}	
			Estado = false;
			System.out.println("A maquina foi desligada");
	}	
	
	public int BuscaVirtual(String nome)
	{

        for(int i= 0; i<5; i++)
        {
        	if(M[i].getVirtual(nome) == true)
        	{
        		return i;
        	}

        }
        	return -1;
	}

	public void apagaVirtual(String nome)
	{	

		float x;
		int cont = 0;
		if(numM>=0)
		{
		 	for(int i= 0; i<5; i++)
			{
        		if(M[i].getVirtual(nome) == true) //verificaçao se a maquina virtual a ser removida existe
        		{	
        			x = M[i].getRam();
        			RamT = x + RamT; //calculo da ram a ser devolvida para a maquina real
        		cont = i;
        		}
        	}
        }
        	
        	M[cont].CriaVirtual(0,0,"");
        	numM = numM -1;
    }	
    public boolean getReal(String Name)
    {
    	if (nome.equals(Name))
        {
            return true;
        }
        else
        {
            return false;
        } 
     }   
     public void Imprime()
     {
     	for(int i=0; i<5; i++)				// imprime todos status da maquina virtual
     	{
     		System.out.println(" nome: "+M[i].getNome() );
     		System.out.println(" ram: "+M[i].getRam() );		
     		System.out.println(" Hd: "+M[i].getHd() );
     		if(M[i].getEstado() == true) System.out.println("ligado");
     		else
     		{
     			System.out.println("Desligado");
     		}
     		
     	}

     }
     public String GetNome()
     {
     	return nome;
     }
     public float GetRam()
     {
     	return RamT;
     }
     public boolean GetEstado()
     {
     	return Estado;
     }
     public void LigaVirtual(int x)
     {	
     	if(Estado == false)
     	{
     		System.out.println("nao e possivel ligar pois a maquina real esta desligada");
     	}
     	else
     	{
     		M[x].ligar();
  	   	}
 }
     public void DesligaVirtual(int x)
     {
     	M[x].desligar();
     }
     public int verificaVirtual(String name)
     {
     	for(int i= 0; i<5; i++)
     	{
     		if (M[i].getVirtual(name) ==true)
        	{
            return i;
        	}
  
        }
        return -1;
     	
     }
     public boolean getEstadoVirtual(int x)
     {
     	return M[x].getEstado();
     }


}