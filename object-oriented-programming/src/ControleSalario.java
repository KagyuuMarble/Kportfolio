public class ControleSalario
{
   private static int somaSalarioBase;
   private static int somaSalarioBonificado;
   //gets
   public static int getsomaSalariosBase()
   {
      return somaSalarioBase;
   }
   public static int getsomaSalariosBonificados()
   {
      return somaSalarioBonificado;
   }
   //metodos
   public static void somaBase(Funcionario v_aux[])
   {
      int i = 0;
      for(i = 0; i < v_aux.length; i++)
      {
         somaSalarioBase +=  v_aux[i].getSalario();
      }
      
   }
   
   public static void somaBonificada(Funcionario v_aux[])
   {
      int i = 0;
      for(i = 0; i < v_aux.length; i++)
      {
         somaSalarioBonificado +=  v_aux[i].getSalarioComBonificacao();
      }
      
   }
}