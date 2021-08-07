public class UsaIntegerSet
{
        public static void main(String args[])
        {
            IntegerSet array1 =  new IntegerSet();
            IntegerSet array2 =  new IntegerSet();
            array1.InsertElement(50);
            array1.InsertElement(30);
            array1.InsertElement(20);
            array1.InsertElement(10);
            array1.InsertElement(40);
            array1.InsertElement(23);
            array2.InsertElement(50);
            array2.InsertElement(30);
            array2.InsertElement(20);
            array2.InsertElement(10);
            array2.InsertElement(40);
            array2.InsertElement(23);
            System.out.println(" " + array1.toSetString() );
            if(array2.isEqualTo(array1)==1) System.out.println("sao iguais ");
            else
                {
                    System.out.println(" nao sao iguais");
                }

            }



}
