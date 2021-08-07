public class IntegerSet
{

    private boolean array[] ;

    public IntegerSet()
    {
        for(int i = 0; i<101; i++)
        {
            array[i]= false;
        }

    }

    public void Union(IntegerSet x, IntegerSet y)
    {
        for(int i=0; i<101; i++)
        {
            if(x.array[i]== true || y.array[i] == true )
            {
                array[i]=true;
            }
            else
            {
                array[i]=false;
            }
        }
    }
    public void Intersection(IntegerSet x, IntegerSet y)
    {

        for(int i=0; i<101; i++)
        {
            if(x.array[i]== true && y.array[i] == true )
            {
                array[i]=true;
            }
            else
            {
                array[i]=false;
            }
        }

    }
    public void InsertElement(int k)
    {
        if(k>=0 || k<101)
        {
            array[k]= true;
        }
    }
    public void DeletElement(int k)
    {
        if(k>=0 || k<101)
        {
            array[k]= false;
        }
    }
 /*   public String toSetString(String x)
    {
        int i, cont;
        cont = 0;
        for(i = 0; i < 101; i++)
        {
            if(array[i] == true)
            {
                x = i;
                cont++;
            }
        }
        return x;

    }
    */
    public int isEqualTo(IntegerSet x)
    {
        for(int i=0; i<101; i++)
        {
            if(array[i]!=x.array[i])
            {
                return 0;
            }
        }
        return 1;
    }
}
