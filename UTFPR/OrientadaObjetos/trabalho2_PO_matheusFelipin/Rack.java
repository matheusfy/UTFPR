import java.util.Scanner;

public class Rack
{


    public static void main(String[] Args )
    {
        MaquinaReal [] MR = new MaquinaReal[5];

        for(int i = 0; i<5; i++)
        {
            MR[i] = new MaquinaReal();
        }
        Scanner teclado = new Scanner(System.in);


        int opcao1=0;
        int posicao=0;
        boolean p;
        String name;
        do
        {
            p = false;
            System.out.println("1 - Criar maquina real ");
            System.out.println("2 - Criar maquina virtual");
            System.out.println("3 - Mostrar maquinas reais existentes");
            System.out.println("4 - Mostrar maquina virtual ");
            System.out.println("5 - Ram disponivel em cada maquina real");
            System.out.println("6 - Ligar/Desligar maquina real");
            System.out.println("7 - Ligar/Desligar maquina virtual");
            System.out.println("8 - ");
            System.out.println("9 - ");
            System.out.println("10- ");
            System.out.println("11- Sair");
            System.out.print("Entre com uma opcao: ");
            opcao1 = teclado.nextInt();
            switch(opcao1)
            {
            case 1:
                CriarReal(MR);
                break;
            case 2:
                CriarVirtual(MR);
                break;
            case 3:
                for(int i=0; i<5; i++)
                {
                    System.out.println(" "+MR[i].GetNome());
                    System.out.println(" "+MR[i].GetEstado());
                }
                break;
            case 4:
                imprimeVirtual(MR);
                break;
            case 5:
                for(int i = 0; i<5; i++)
                {
                    System.out.println(" "+MR[i].GetNome());   //imprime o nome da maquina real
                    System.out.println(" "+MR[i].GetRam());    //imprime o quanto de ram disponivel
                }
                break;
            case 6:
                LigaDesligaReal(MR);
                break;
            case 7:
                String x;
                System.out.println("Insira o nome da sua maquina real que esta a maquina virtual que deseja ligar/desligar");
                x = teclado.nextLine();

                if(verificacao(MR,x) == true) LigaDesligaVirtual(MR);
                else
                {
                    System.out.println("nao existe uma maquina real com este nome");
                }
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:

                break;

            }
        }
        while(opcao1 != 11);
    }


    public static void CriarReal(MaquinaReal[] Mr)
    {
        float ramm,hdd;
        String Nome;
        boolean flag = false;
        Scanner teclado = new Scanner(System.in);
        int cont = 0;

        for(int i = 0; i<5; i++)
        {
            if( Mr[i].getReal("") == true)
            {
                flag =true;
                cont = i;
                break;
            }
        }
        if(flag == true)
        {

            System.out.println("Insira o valor de Ram da sua maquina real");
            ramm = teclado.nextFloat();

            System.out.println("Insira o valor de HD da sua maquina real");
            hdd = teclado.nextFloat();

            teclado.nextLine();
            System.out.println("Insira o nome da sua maquina real");
            Nome = teclado.nextLine();

            Mr[cont].CriaReal(ramm,hdd,Nome);

        }
    }
    public static void CriarVirtual(MaquinaReal[] Mr)
    {
        float ramm,hdd;
        String Nome;
        boolean flag = false;
        Scanner teclado = new Scanner(System.in);
        int cont = 0;
        String x;
        System.out.println("Insira o nome da sua maquina real");
        x = teclado.nextLine();


        if(verificacao(Mr,x) == true) // se sim , cria uma maquina virtual
        {


            System.out.println("Insira o valor de Ram da sua maquina Virtual");
            ramm = teclado.nextFloat();

            System.out.println("Insira o valor de HD da sua maquina Virtual");
            hdd = teclado.nextFloat();

            teclado.nextLine();
            System.out.println("Insira o nome da sua maquina Virtual");
            Nome = teclado.nextLine();

            Mr[cont].CriarVirtual(ramm, hdd, Nome);
        }
        else
        {
            System.out.println("nao existe uma maquina real com este nome");
        }
    }

    public static void imprimeVirtual(MaquinaReal[] Mr)
    {
        Scanner teclado = new Scanner (System.in);
        String nome;
        boolean flag = false;


        System.out.println("insira o nome da maquina real que deseja ver as maquinas virtuais");
        nome = teclado.nextLine();

        for(int i = 0; i<5; i++)
        {
            if( Mr[i].getReal(nome) == true)    //verificaçao se existe a maquina real pedida
            {
                flag = true;
                Mr[i].Imprime();    // se sim imprime todas as maquinas virtuais existentes nela e o estado
            }
        }
        if(flag == false) System.out.println("nao existe uma maquina real com este nome");

    }

    public static void LigaDesligaReal(MaquinaReal[] Mr)
    {
        Scanner teclado = new Scanner (System.in);
        String nome;
        int posicao = 0;
        System.out.println("insira o nome da maquina real que deseja ver as maquinas virtuais");
        nome = teclado.nextLine();
        posicao = verificacao2(Mr,nome);
        if(posicao!=-1)
        {
            System.out.println("Situacao da maquina :"+Mr[posicao].GetEstado());
            if(Mr[posicao].GetEstado() == true)
            {
                System.out.println("atualmente esta ligado, deseja desligar?");
                System.out.println("1 - Sim");
                System.out.println("0 - Nao");
                int opcao ;
                opcao = teclado.nextInt();
                if(opcao == 1)
                {
                    Mr[posicao].Desligar();
                }
                else
                {
                    System.out.println("nao foi desligado");
                }
            }
            else
            {
                System.out.println("atualmente esta desligado, deseja ligar?");
                System.out.println("1 - Sim");
                System.out.println("0 - Nao");
                int opcao ;
                opcao = teclado.nextInt();
                if(opcao == 1)
                {
                    Mr[posicao].Ligar();
                }
                else
                {
                    System.out.println("nao foi ligada");
                }
            }
        }
    }

    public static boolean verificacao(MaquinaReal[] Mr, String x)
    {
        for(int i = 0; i<5; i++)
        {
            if( Mr[i].getReal(x) == true) // verificaçao se existe a maquina real exijida
            {
                return true;
            }
        }
        return false;
    }
    public static int verificacao2(MaquinaReal[] Mr, String x)
    {
        for(int i = 0; i<5; i++)
        {
            if( Mr[i].getReal(x) == true) // verificaçao se existe a maquina real exijida
            {
                return i;
            }
        }
        return -1;
    }
    public static void LigaDesligaVirtual(MaquinaReal[] Mr)
    {
        Scanner teclado = new Scanner(System.in);
        String x;
        String y;
        int posicao, posicao2;
        System.out.println("Insira o nome da sua maquina real");
        x = teclado.nextLine();
        posicao = verificacao2(Mr,x);
        if(posicao!= -1)
        {
            System.out.println("Insira o nome da sua maquina virtual que deseja ligar/desligar");
            y = teclado.nextLine();
            posicao2 = Mr[posicao].verificaVirtual(y);
            if( posicao2 !=-1)
            {
                if(Mr[posicao].getEstadoVirtual(posicao2) == true)
                {
                    int opcao;
                    System.out.println("atualmente esta ligado, deseja desligar?");
                    System.out.println("1 - Sim");
                    System.out.println("0 - Nao");
                    opcao = teclado.nextInt();
                    if(opcao == 1)
                    {
                        Mr[posicao].DesligaVirtual(posicao2);
                    }
                    else
                    {
                        System.out.println("nao foi desligado");
                    }
                }
                else
                {
                    System.out.println("atualmente esta desligado, deseja ligar?");
                    System.out.println("1 - Sim");
                    System.out.println("0 - Nao");
                    int opcao ;
                    opcao = teclado.nextInt();
                    if(opcao == 1)
                    {
                        Mr[posicao].LigaVirtual(posicao2);
                    }
                    else
                    {
                        System.out.println("nao foi ligada");
                    }
                }
            }

        }
        else
        {
            System.out.println("nao existe uma maquina real com este nome");
        }
    }
}
