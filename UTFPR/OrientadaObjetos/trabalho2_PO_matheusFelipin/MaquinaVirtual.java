public class MaquinaVirtual{

	private boolean estado;
	private float ram;
	private float hd;
	private String nome; 

	public MaquinaVirtual()
	{
		this.ram = 0;
		this.hd = 0;
		this.estado = false;
		this.nome = "";

	}
	public void CriaVirtual(float R, float H,String N)
	{
		this.ram = R;
		this.hd = H;
		this.estado = false;
		this.nome = N;
	}
	public void ligar()
	{
		estado = true;
		
	}
	public void desligar()
	{
		estado = false;
		
	}
	public boolean getVirtual(String name)
	{
		if (nome.equals(name))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public float getRam()
    {
    	return ram;
    }
     public float getHd()
    {
    	return hd;
    }
    public String getNome()
    {
    	return nome;
    }
    public boolean getEstado()
    {
    	return estado;
    }

}